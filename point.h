#pragma once
class Point
{
public:
    Point(const int x, const int y) : x(x), y(y) {}
    void Print();//打印输出方块
    void Clear();//清除输出
    void ChangePosition(const int x, const int y);//改变坐标
    bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
    int GetX() { return this->x; }
    int GetY() { return this->y; }
private:
    int x, y;
};

