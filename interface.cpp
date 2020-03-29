#include "interface.h"
#include <windows.h>

void StartInterface::PrintFirst()//������߳��ֵ���ȫ���ֵĹ���
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);//print�������������
    }
}

void StartInterface::PrintSecond()//���������ƶ��Ĺ���
{
    for (int i = 10; i != 38; ++i) //��Ҫ��10�ƶ���38
    {
        /*������һ��λ�ã�������ѹ��startsnake�У����Ƴ�������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);//�������ʽ ? ��ֵ : ��ֵ
        startsnake.emplace_back(Point(i, j));//�����i��jԪ�ص�startsnake��
        startsnake.back().Print();//��ӡβ���ķ���
        startsnake.front().Clear();//���ͷ���ķ���
        startsnake.pop_front();//ɾ����һ��Ԫ�أ��ͷ��ڴ棬vector��֧��deque˫��
        Sleep(speed);
    }
}

void StartInterface::PrintThird()//���߽Ӵ��ұߵ���ʧ�Ĺ���
{
    while (!startsnake.empty() || textriddle.back().GetX() < 33) //���߻�û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake.empty()) //������߻�û��ʧ�������ƶ�
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//�����������
        PrintText();//���Ƹ���λ�ú������
        Sleep(speed);
    }
}

void StartInterface::PrintText()
{
    for (auto& point : textriddle)   //��˵һ��Auto���Ϳ����ƶϱ��������ͣ�����ʹ�õ�ʱ������ȳ�ʼ��
    {
        if (point.GetX() >= 0)
            point.Print();
    }
}

void StartInterface::ClearText()
{
    for (auto& point : textriddle) //�����ͬʱ���������������ƶ�һ��
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

void OverInterface::PrintFirst()//������߳��ֵ���ȫ���ֵĹ���
{
    for (auto& point : startsnake)
    {
        point.Print();
        Sleep(speed);
    }
}

void OverInterface::PrintSecond()//���������ƶ��Ĺ���
{
    for (int i = 10; i != 38; ++i) //��Ҫ��10�ƶ���38
    {
        /*������һ��λ�ã�������ѹ��startsnake�У����Ƴ�������βȥ��*/
        int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
        startsnake.emplace_back(Point(i, j));
        startsnake.back().Print();
        startsnake.front().Clear();
        startsnake.pop_front();
        Sleep(speed);
    }
}

void OverInterface::PrintThird()//���ߴӽӴ��ұߵ���ʧ�Ĺ���
{
    while (!startsnake.empty() || textriddle.back().GetX() < 30) //��û��ʧ������û�ƶ���ָ��λ��
    {
        if (!startsnake.empty()) //�����û��ʧ�������ƶ�
        {
            startsnake.front().Clear();
            startsnake.pop_front();
        }
        ClearText();//�����������
        PrintText();//���Ƹ���λ�ú������
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
    for (auto& point : textriddle) //�����ͬʱ���������������ƶ�һ��
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

