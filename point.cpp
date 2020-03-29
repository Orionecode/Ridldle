#include "point.h"
#include "Riddle.h"
#include <iostream>

void Point::Print()//输出方块
{
    SetCursorPosition(x, y);
    std::cout << "■";
}


void Point::Clear()//清除输出
{
    SetCursorPosition(x, y);
    std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y)//改变坐标
{
    this->x = x;
    this->y = y;
}
