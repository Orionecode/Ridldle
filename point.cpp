#include "point.h"
#include "Riddle.h"
#include <iostream>

void Point::Print()//�������
{
    SetCursorPosition(x, y);
    std::cout << "��";
}


void Point::Clear()//������
{
    SetCursorPosition(x, y);
    std::cout << "  ";
}

void Point::ChangePosition(const int x, const int y)//�ı�����
{
    this->x = x;
    this->y = y;
}