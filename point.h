#pragma once
class Point
{
public:
    Point(const int x, const int y) : x(x), y(y) {}
    void Print();//��ӡ�������
    void Clear();//������
    void ChangePosition(const int x, const int y);//�ı�����
    bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
    int GetX() { return this->x; }
    int GetY() { return this->y; }
private:
    int x, y;
};

