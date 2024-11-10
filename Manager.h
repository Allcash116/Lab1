//
// Created by Владислав Ковригин on 06.10.2024.
//

#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <unistd.h>

#include "Coordinats.h"
#include "LineSettings.h"
#include "Line.h"

using namespace std;

class Manager {
    vector<Line*> Lines;

    LineSettings _lineSettings = LineSettings();
    Console console = Console();
    Coordinats coordinats_ = Coordinats();

    int width;
    int height;
    int randomHeight;
    int Voltage_;

    int sleepMs;
    int sumMS;
    int quant;
    int name = 0;

    int time[15];


    void getData(LineSettings data) {
        system("clear");

        cout << "Скорость:    d";
        string speed;
        cin >> speed;
        speed = checkInt(speed);
        data.Speed_ = stoi(speed);
        data.Speed_ = 1000 / data.Speed_;
        _lineSettings.Speed_ = data.Speed_;

        cout << "Длина: ";
        string lenght;
        cin >> lenght;
        lenght = checkInt(lenght);
        data.Lenght_ = stoi(lenght);
        _lineSettings.Lenght_ = data.Lenght_;

        cout << "Количество линий в секунду: ";
        string voltage;
        cin >> voltage;
        voltage = checkInt(voltage);
        Voltage_ = stoi(voltage);

        cout << "Режим эпилепсии ";
        cout << "Введите знак (Y/N): ";
        cin >> data.Choise_;
        checkChar(data.Choise_);
        _lineSettings.Choise_ = data.Choise_;
    }

public:
    Manager(int argc, char* argv[]) {
        if (argc > 1) {
            string speed = checkInt(argv[1]);
            _lineSettings.Speed_ = 1000 / stoi(speed);
            string length = checkInt(argv[2]);
            _lineSettings.Lenght_= stoi(length);
            char choise = argv[3][0];
            _lineSettings.Choise_ = choise;
            checkChar(_lineSettings.Choise_);

            ManagerStart();
        }
        else {
            getData(_lineSettings);
            ManagerStart();
        }
    }
    void ManagerStart();
private:
    string checkInt(string str) {
        if (isInteger(str)) {
            int Num = stoi(str);
            if (Num > 30 || Num < 1 || Num) {
                while (Num > 30 || Num < 1) {
                    cout << "Неверное значение! (1-30)";
                    cin >> str;
                    if (isInteger(str)) {
                        Num = stoi(str);
                    }
                }
            }
        }
        else {
            while(!isInteger(str)) {
                cout << "вы ввели не число, введите число: ";
                cin >> str;
            }
            int Num = stoi(str);
            if (Num > 30 || Num < 1 || Num) {
                while (Num > 30 || Num < 1) {
                    cout << "Неверное значение! (1-30)";
                    cin >> str;
                    if (isInteger(str)) {
                        Num = stoi(str);
                    }
                }
            }
        }
        return str;
    }
    bool isInteger(string str) {
        if (str.empty()) return false;

        size_t start = 0;
        if (str[0] == '+' || str[0] == '-') {
            start = 1;
        }

        for (size_t i = start; i < str.size(); ++i) {
            if (!isdigit(str[i])) {
                return false;
            }
        }

        return true;
    }
    void checkChar(char Sym) {
        do {
            // Приведение к верхнему регистру для проверки
            Sym = toupper(Sym);

            if (Sym == 'Y' || Sym == 'N') {
                cout << "Вы ввели допустимый знак: " << Sym << std::endl;
            } else {
                std::cout << "Недопустимый ввод. Пожалуйста, введите Y или N." << std::endl;
                cin >> Sym;
            }

        }
        while (Sym != 'Y' && Sym != 'N');

    }

};



#endif //MANAGER_H
