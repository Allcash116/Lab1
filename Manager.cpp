

#include "Manager.h"
#include <thread>

using namespace std;

void Manager::ManagerStart() {

    system("clear");

    while(true) {
        console.getConsoleSize(width,height);
        system("Clear");
        Line line = Line(1,coordinats_.getRandomHeight());
        for(int i = 0; i < width + _lineSettings.Lenght_; i++) {
            line.updateLine(width,height,_lineSettings);
        }
    }
}

/*
 *Статические методы консоли
 *Поменять название методов
 *Следовать принципу SOLID
 *Следить за одинаковыми кусками кода
 *Продумать структуру программы еще раз
 *Объявлять в header только название методов и переменные
 *Придумать алгоритм отрисовки кажого кадра
 */