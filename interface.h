#pragma once
#include <deque>
#include <vector>
#include "point.h"

class StartInterface
{
public:
    StartInterface() //构造StartInter构造函数
    {
        speed = 50;                            //设定速度等于50
        startsnake.emplace_back(Point(0, 14)); //扭动
        startsnake.emplace_back(Point(1, 14));
        startsnake.emplace_back(Point(2, 15));
        startsnake.emplace_back(Point(3, 16));
        startsnake.emplace_back(Point(4, 17));
        startsnake.emplace_back(Point(5, 18));
        startsnake.emplace_back(Point(6, 17));
        startsnake.emplace_back(Point(7, 16));
        startsnake.emplace_back(Point(8, 15));
        startsnake.emplace_back(Point(9, 14));

        textriddle.emplace_back(Point(-29, 14)); //R
        textriddle.emplace_back(Point(-29, 15));
        textriddle.emplace_back(Point(-29, 16));//使用vector中的emplace_back是往textriddle向量容器中添加Point数据
        textriddle.emplace_back(Point(-29, 17));//没有使用push_back的原因是emplace_back 可以减少内存的拷贝和移动
        textriddle.emplace_back(Point(-29, 18));
        textriddle.emplace_back(Point(-28, 14));
        textriddle.emplace_back(Point(-28, 16));
        textriddle.emplace_back(Point(-28, 17));
        textriddle.emplace_back(Point(-27, 14));
        textriddle.emplace_back(Point(-27, 15));
        textriddle.emplace_back(Point(-27, 16));
        textriddle.emplace_back(Point(-27, 18));

        textriddle.emplace_back(Point(-23, 14)); //I
        textriddle.emplace_back(Point(-23, 15));
        textriddle.emplace_back(Point(-23, 16));
        textriddle.emplace_back(Point(-23, 17));
        textriddle.emplace_back(Point(-23, 18));

        textriddle.emplace_back(Point(-19, 18)); //D
        textriddle.emplace_back(Point(-19, 17));
        textriddle.emplace_back(Point(-19, 16));
        textriddle.emplace_back(Point(-19, 15));
        textriddle.emplace_back(Point(-19, 14));
        textriddle.emplace_back(Point(-18, 18));
        textriddle.emplace_back(Point(-18, 14));
        textriddle.emplace_back(Point(-17, 17));
        textriddle.emplace_back(Point(-17, 15));
        textriddle.emplace_back(Point(-17, 16));

        textriddle.emplace_back(Point(-12, 18)); //D
        textriddle.emplace_back(Point(-12, 17));
        textriddle.emplace_back(Point(-12, 16));
        textriddle.emplace_back(Point(-12, 15));
        textriddle.emplace_back(Point(-12, 14));
        textriddle.emplace_back(Point(-11, 18));
        textriddle.emplace_back(Point(-11, 14));
        textriddle.emplace_back(Point(-10, 17));
        textriddle.emplace_back(Point(-10, 15));
        textriddle.emplace_back(Point(-10, 16));

        textriddle.emplace_back(Point(-6, 14)); //I
        textriddle.emplace_back(Point(-6, 15));
        textriddle.emplace_back(Point(-6, 16));
        textriddle.emplace_back(Point(-6, 17));
        textriddle.emplace_back(Point(-6, 18));

        textriddle.emplace_back(Point(-2, 14)); //E
        textriddle.emplace_back(Point(-2, 15));
        textriddle.emplace_back(Point(-2, 16));
        textriddle.emplace_back(Point(-2, 17));
        textriddle.emplace_back(Point(-2, 18));
        textriddle.emplace_back(Point(-1, 14));
        textriddle.emplace_back(Point(-1, 16));
        textriddle.emplace_back(Point(-1, 18));
        textriddle.emplace_back(Point(0, 14));
        textriddle.emplace_back(Point(0, 16));
        textriddle.emplace_back(Point(0, 18));
    }
    void PrintFirst();
    void PrintSecond();
    void PrintThird();
    void PrintText();
    void ClearText();
    void Action();

private:
    std::deque<Point> startsnake;  //开始动画中的曲线，与vector不同，deque支持高效插入和删除容器的头部元素，因此也叫做双端队列。
    std::vector<Point> textriddle; //开始动画中的文字，创建了一个属于Point类的向量储存容器，名字为textriddle
    int speed;                     //动画的速度
};
class OverInterface
{
public:
    OverInterface()
    {
        speed = 50;
        startsnake.emplace_back(Point(0, 14)); //扭曲的灵魂
        startsnake.emplace_back(Point(1, 14));
        startsnake.emplace_back(Point(2, 15));
        startsnake.emplace_back(Point(3, 16));
        startsnake.emplace_back(Point(4, 17));
        startsnake.emplace_back(Point(5, 18));
        startsnake.emplace_back(Point(6, 17));
        startsnake.emplace_back(Point(7, 16));
        startsnake.emplace_back(Point(8, 15));
        startsnake.emplace_back(Point(9, 14));

        textriddle.emplace_back(Point(-24, 11)); //O
        textriddle.emplace_back(Point(-24, 12));
        textriddle.emplace_back(Point(-24, 13));
        textriddle.emplace_back(Point(-24, 14));
        textriddle.emplace_back(Point(-24, 15));
        textriddle.emplace_back(Point(-25, 11));
        textriddle.emplace_back(Point(-25, 15));
        textriddle.emplace_back(Point(-26, 11));
        textriddle.emplace_back(Point(-26, 15));
        textriddle.emplace_back(Point(-27, 11));
        textriddle.emplace_back(Point(-27, 12));
        textriddle.emplace_back(Point(-27, 13));
        textriddle.emplace_back(Point(-27, 14));
        textriddle.emplace_back(Point(-27, 15));

        textriddle.emplace_back(Point(-20, 11)); //V
        textriddle.emplace_back(Point(-20, 12));
        textriddle.emplace_back(Point(-19, 13));
        textriddle.emplace_back(Point(-19, 14));
        textriddle.emplace_back(Point(-18, 15));
        textriddle.emplace_back(Point(-17, 14));
        textriddle.emplace_back(Point(-17, 13));
        textriddle.emplace_back(Point(-16, 12));
        textriddle.emplace_back(Point(-16, 11));

        textriddle.emplace_back(Point(-11, 11)); //E
        textriddle.emplace_back(Point(-11, 12));
        textriddle.emplace_back(Point(-11, 13));
        textriddle.emplace_back(Point(-11, 14));
        textriddle.emplace_back(Point(-11, 15));
        textriddle.emplace_back(Point(-10, 11));
        textriddle.emplace_back(Point(-10, 13));
        textriddle.emplace_back(Point(-10, 15));
        textriddle.emplace_back(Point(-9, 11));
        textriddle.emplace_back(Point(-9, 13));
        textriddle.emplace_back(Point(-9, 15));

        textriddle.emplace_back(Point(-5, 11)); //R
        textriddle.emplace_back(Point(-5, 12));
        textriddle.emplace_back(Point(-5, 13));
        textriddle.emplace_back(Point(-5, 14));
        textriddle.emplace_back(Point(-5, 15));
        textriddle.emplace_back(Point(-4, 11));
        textriddle.emplace_back(Point(-4, 13));
        textriddle.emplace_back(Point(-4, 14));
        textriddle.emplace_back(Point(-3, 11));
        textriddle.emplace_back(Point(-3, 12));
        textriddle.emplace_back(Point(-3, 13));
        textriddle.emplace_back(Point(-3, 15));
    }
    void PrintFirst();
    void PrintSecond();
    void PrintThird();
    void PrintText();
    void ClearText();
    void Action();

private:
    std::deque<Point> startsnake;  //开始动画中的蛇
    std::vector<Point> textriddle; //开始动画中的文字
    int speed;                     //动画的速度
};
