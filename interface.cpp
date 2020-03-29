#include "interface.h"
#include <windows.h>

void StartInterface::PrintFirst()//曲线左边出现到完全出现的过程
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);//print间隔的秒数控制
    }
}

void StartInterface::PrintSecond()//从左向右移动的过程
{
    for (int i = 10; i != 38; ++i) //需要从10移动到38
    {
        /*计算下一个位置，并将其压入startsnake中，绘制出来，将尾去掉*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);//条件表达式 ? 真值 : 假值
        startsnake.emplace_back(Point(i, j));//添加了i，j元素到startsnake中
        startsnake.back().Print();//打印尾部的方块
        startsnake.front().Clear();//清除头部的方块
        startsnake.pop_front();//删除第一个元素，释放内存，vector不支持deque双向
        Sleep(speed);
    }
}

void StartInterface::PrintThird()//曲线接触右边到消失的过程
{
    while (!startsnake.empty() || textriddle.back().GetX() < 33) //曲线还没消失或文字没移动到指定位置
    {
        if (!startsnake.empty()) //如果曲线还没消失，继续移动
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//清除已有文字
        PrintText();//绘制更新位置后的文字
        Sleep(speed);
    }
}

void StartInterface::PrintText()
{
    for (auto& point : textriddle)   //简单说一下Auto类型可以推断变量的类型，但是使用的时候必须先初始化
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}

void StartInterface::ClearText()
{
    for (auto& point : textriddle) //清除的同时将文字整体向右移动一格
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void StartInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}

void OverInterface::PrintFirst()//曲线左边出现到完全出现的过程
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}

void OverInterface::PrintSecond()//从左向右移动的过程
{
    for (int i = 10; i != 38; ++i) //需要从10移动到38
    {
        /*计算下一个位置，并将其压入startsnake中，绘制出来，将尾去掉*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}

void OverInterface::PrintThird()//曲线从接触右边到消失的过程
{
    while (!startsnake.empty() || textriddle.back().GetX() < 30) //还没消失或文字没移动到指定位置
    {
        if (!startsnake.empty()) //如果还没消失，继续移动
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//清除已有文字
        PrintText();//绘制更新位置后的文字
        Sleep(speed);
    }
}

void OverInterface::PrintText()
{
    for (auto& point : textriddle)
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}

void OverInterface::ClearText()
{
    for (auto& point : textriddle) //清除的同时将文字整体向右移动一格
    {
        if (point.GetX() >= 0)
            point.Clear();
        point.ChangePosition(point.GetX() + 1, point.GetY());
    }
}

void OverInterface::Action()
{
    PrintFirst();
    PrintSecond();
    PrintThird();
}

