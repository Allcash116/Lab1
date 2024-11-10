//
// Created by Владислав Ковригин on 06.10.2024.
//

#ifndef COORDINATS_H
#define COORDINATS_H


#include "Console.h"
#include "Symbol.h"
using namespace std;

class Coordinats {
private:
    Console console;
    Symbol symbol;
    int height;
    int width;
    int randomHeight;
public:
    int getRandomHeight() {
        console.getConsoleSize(width,height);
        randomHeight = symbol.getRandomInt(height);
        console.setCursorPosition(1,1);
        return randomHeight;
    }
};



#endif //COORDINATS_H
