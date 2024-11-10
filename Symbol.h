//
// Created by Владислав Ковригин on 06.10.2024.
//

#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include <random>
#include <iostream>

#include "Console.h"
#include "LineSettings.h"

using namespace std;

class Symbol {
private:
    int height;
    int width;
    Console console;
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";// Набор символов
    int arr[8] = {30, 31, 32, 33, 34, 35, 36, 37};
    char sym = ' ';
    char symbols[3];

    void drawLastSym(int i, int randomHeight, bool end, char Choise) {
        if (Choise == 'n') {
            console.setTextColor(32);
            if (end == true) {
                if (i % 2 == 0) {
                    console.setCursorPosition(i, randomHeight + 1);
                    cout << symbols[0];
                    console.setCursorPosition(i, randomHeight - 1);
                    cout << symbols[1];
                }
                else {
                    console.setCursorPosition(i, randomHeight);
                    cout << symbols[2];
                }
            }
            if ((i - 1) % 2 == 0) {
                console.setCursorPosition(i - 1, randomHeight + 1);
                cout << symbols[0];
                console.setCursorPosition(i - 1, randomHeight - 1);
                cout << symbols[1];
            }
            else {
                console.setCursorPosition(i - 1, randomHeight);
                cout << symbols[2];
            }
        }
        else {
            if (end == true) {
                if (i % 2 == 0) {
                    console.setCursorPosition(i, randomHeight + 1);
                    console.setTextColor(getRandomColor());
                    cout << symbols[0];
                    console.setCursorPosition(i, randomHeight - 1);
                    console.setTextColor(getRandomColor());
                    cout << symbols[1];
                }
                else {
                    console.setCursorPosition(i, randomHeight);
                    console.setTextColor(getRandomColor());
                    cout << symbols[2];
                }
            }
            if ((i - 1) % 2 == 0) {
                console.setCursorPosition(i - 1, randomHeight + 1);
                console.setTextColor(getRandomColor());
                cout << symbols[0];
                console.setCursorPosition(i - 1, randomHeight - 1);
                console.setTextColor(getRandomColor());
                cout << symbols[1];
            }
            else {
                console.setCursorPosition(i - 1, randomHeight);
                console.setTextColor(getRandomColor());
                cout << symbols[2];
            }

        }

    }
public:
    char getRandomChar() {
        // Генератор случайных чисел
        random_device seed;  // Использует аппаратный генератор случайных чисел
        mt19937 gen(seed());  // Инициализация генератора
        uniform_int_distribution<> dis(0, charset.size() - 1); // Равномерное распределение

        return charset[dis(gen)];
    }

    void drawSymbol(int x, int y, char Choise) {
        console.setCursorPosition(x,y);
        sym = getRandomChar();
        cout << sym;
    }

    void draw(int i, int randomHeight, char Choise, int width) {
            console.setTextColor(37);
        if (i % 2 == 0) {
            drawSymbol(i, randomHeight + 1, Choise);
            symbols[0] = sym;
            drawSymbol(i, randomHeight - 1, Choise);
            symbols[1] = sym;
            console.setCursorPosition(1,1);
        }
        else {
            drawSymbol(i, randomHeight, Choise);
            symbols[2] = sym;
            console.setCursorPosition(1,1);
        }

        if (i > 1 && i < width) {
            drawLastSym(i, randomHeight, false, Choise);
            console.setCursorPosition(1,1);
        }
        if (i == width) {
            drawLastSym(i, randomHeight, true, Choise);
            console.setCursorPosition(1,1);
        }
    }

    void clearLastSymbol(int i, int randomHeight, int Lenght_) {
        if ((i - Lenght_) % 2 == 0) {
            console.setCursorPosition(i - Lenght_,randomHeight + 1);
            cout << " ";
            console.setCursorPosition(i - Lenght_, randomHeight - 1);
            cout << " ";
            console.setCursorPosition(1,1);
        }
        else {
            console.setCursorPosition(i - Lenght_, randomHeight);
            cout << " ";
            console.setCursorPosition(1,1);
        }
    }


    int getRandomColor() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(30, 36);
        int random_number = distr(gen);
        return random_number;
    }

    int getRandomInt(int y) {
        random_device sd;
        mt19937 gen(sd());
        uniform_int_distribution<> distr(2, (y - 1));
        int random_number = distr(gen);
        return random_number;
    }

};



#endif //SYMBOL_H
