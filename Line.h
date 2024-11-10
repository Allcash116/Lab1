//
// Created by Владислав Ковригин on 06.10.2024.
//


#ifndef LINE_H
#define LINE_H

#include <thread>
#include <chrono>



#include "Symbol.h"
#include "LineSettings.h"

using namespace std;

class Line{
private:
    int CoordinatX = 1;
    int CoordinatY;
    Symbol symbol = Symbol();
public:
    Line(int id, int Y) {
        CoordinatY = Y;
    }
    void updateLine(int width, int height, LineSettings data) {
            if (CoordinatX <= data.Lenght_) {
                symbol.draw(CoordinatX, CoordinatY, data.Choise_, width);
                CoordinatX++;
                this_thread::sleep_for(std::chrono::milliseconds(data.Speed_));
            }
            if (data.Lenght_ < CoordinatX && CoordinatX <= width) {
                symbol.draw(CoordinatX, CoordinatY, data.Choise_, width);
                symbol.clearLastSymbol(CoordinatX, CoordinatY, data.Lenght_);
                CoordinatX++;
                this_thread::sleep_for(std::chrono::milliseconds(data.Speed_));
            }
            if (CoordinatX > width) {
                symbol.clearLastSymbol(CoordinatX, CoordinatY, data.Lenght_);
                CoordinatX++;
                this_thread::sleep_for(std::chrono::milliseconds(data.Speed_));
            }
        }
};



#endif //LINE_H


