#include "Riddle.h"
#include "point.h"
#include "interface.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
int totalscore = 0;//定义全局变量totalscore
int CountLines(char *filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename, ios::in); //ios::in 打开文件进行读取
	if (ReadFile.fail())			  //文件打开失败:返回0
	{
		return 0;
	}
	else //文件存在
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n; //n是文件的行数
	}
}

string ReadLine(char *filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename, ios::in);
	lines = CountLines(filename); //从countlines函数获取行数
	if (line <= 0)
	{
		return "Error 1: 外部文件行数错误，不能为0或负数。";
	}
	if (file.fail())
	{
		return "Error 2: 文件不存在。";
	}
	if (line > lines)
	{
		return "Error 3: 外部文件行数超出文件长度。";
	}
	while (getline(file, temp) && i < line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

bool is_number(string str) //判断是否是小数
{
	/*if (str.c_str()[0] == 45)
	{
		return false;
	}要求有负数时打开*/

	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] < '0' || str.c_str()[i] > '9')
		{
			if (str.c_str()[i] == 46) //支持小数
			{
				return true;
			}
			else
				return false;
		}
	}
}

void SetWindowSize(int cols, int lines) //设置窗口大小
{
	system("title RIDDLE"); //设置窗口标题
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines); //一个图形■占两个字符，故宽度乘以2
	system(cmd);												  //system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y) //设置光标位置
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID) //设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor() //设置文本背景色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
								FOREGROUND_BLUE |
								BACKGROUND_BLUE |
								BACKGROUND_GREEN |
								BACKGROUND_RED);
}
int Controller::Menu() //选择菜单
{
	/*绘制菜单*/
	SetColor(3);
	SetCursorPosition(18, 12);
	std::cout << "菜单：";
	Sleep(100);
	SetCursorPosition(17, 14);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(14, 16);
	SetColor(3);
	std::cout << "不了，还是学习有意思";
	Sleep(100);
	SetCursorPosition(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)//这里的switch代码部分作为光标的移动和tmp_key的转换，只要按回车就会结束while循环
		{
		case 72: //UP键
			if (tmp_key > 1)
			{
				SetCursorPosition(17, 14);
				SetBackColor();
				std::cout << "继续游戏";
				SetCursorPosition(14, 16);
				SetColor(3);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			break;

		case 80: //DOWN键
			if (tmp_key < 2)
			{
				SetCursorPosition(14, 16);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(17, 14);
				SetColor(3);
				std::cout << "继续游戏";
				++tmp_key;
				break;
			}
			break;

		case 13: //Enter
			flag = true;
			break;

		default:
			break;
		}

		if (flag)
		{
			break;
		}
		SetCursorPosition(0, 31);
	}
	return tmp_key;
}

void Riddle::Game() //游戏循环
{

	string Answer;
	int line = getnumber1;
	char filename1[] = "谜面.txt";
	char filename2[] = "谜底.txt";
	char filename3[] = "提示.txt";
	SetCursorPosition(10, 14);
	cout << "外部文件加载成功！"
		 << " 读取到谜语 " << CountLines(filename1) << "个" << '\n';
	SetCursorPosition(14, 16);
	cout << "您抽取的是" << getnumber1 << "号题目" << '\n';
	SetCursorPosition(14, 18);
	Sleep(1500);
	system("cls");
	cout << ReadLine(filename1, line);
	cout << '\n';
	string AnswerInput;
	Answer = ReadLine(filename2, line);
	int count = 0;
	int singlescore;
	while (1)
	{
		cout << "请输入你的答案:";
		string str;
		while (1)
		{
			cin >> str;
			cout << '\n';
			if (is_number(str))
			{
				cout << "请不要输入数字或符号，这是猜谜语游戏！重新输入：";
				count++;
			}
			else
			{
				AnswerInput = str.c_str();
				break;
			}
		}
		cout << '\n';
		count++;
		if (AnswerInput == Answer)
		{
			cout << "恭喜哦，你在第" << count << "次猜对了";
			cout << '\n';
			if (count == 1)
			{
				singlescore = 10;
				totalscore = singlescore + totalscore;
				cout << "您目前的总分数是：" << totalscore
					 << "，小题分：" << singlescore << '\n';
			}
			if (count > 1 && count <= 4)
			{
				singlescore = 5;
				totalscore = singlescore + totalscore;
				cout << "您目前的总分数是：" << totalscore
					 << "，小题分：" << singlescore << '\n';
			}
			if (count > 4 && count < 8)
			{
				singlescore = 1;
				totalscore = singlescore + totalscore;
				cout << "您目前的总分数是：" << totalscore
					 << "，小题分：" << singlescore << '\n';
			}
			if (count > 8)
			{
				singlescore = 0;
				totalscore = singlescore + totalscore;
				cout << "您目前的总分数是：" << totalscore
					 << "，小题分：" << singlescore << '\n';
			}
			break;
		}
		else
		{
			cout << "答案错误，请再试一次。" << '\n';
			if (count >= 3)
			{
				cout << ReadLine(filename3, line) << '\n';
				cout << '\n';
			}
			if (count >= 10)
			{
				system("cls");
				SetCursorPosition(17, 14);
				OverInterface *Over = new OverInterface(); //动态分配一个OverInterface类Over，new创建的对象不是用“*”或“.”来访问该对象的成员函数的，而是用运算符“->”
				Over->Action();							//结束动画
				SetCursorPosition(8, 17);
				cout << "你已经尝试了十次了，答案是 " << Answer << " ,下次加油哦！" << '\n';
				SetCursorPosition(15, 19);
				break;
			}
		}
	}
}
int Riddle::PlayGame()
{
	int Q = 0;
	char filename1[] = "谜面.txt";
	Q = CountLines(filename1);                    //Q的值代表了生成随机数的趟数
	SetWindowSize(38, 32);						  //设置窗口大小
	SetColor(3);								  //设置开始动画颜色
	StartInterface* start = new StartInterface(); //动态分配一个StartInterface类start 使用new必须用->来调用
	start->Action();							  //开始动画；与StartInterface start；start.action()基本上相同
	SetCursorPosition(22, 25);
	std::cout << "Press any key to start... ";	  //设置关标位置，并输出提示语，等待任意键输入结束
	SetCursorPosition(22, 26);
	system("pause");
	system("cls");

	while (1)
	{
		int a[100];
		srand((unsigned)time(NULL));
		for (int i = 0; i < Q; i++) //循环生成随机数并储存到a数组中
		{
			a[i] = rand() % Q + 1;
			int j = i;
			while (j--)
			{
				if (a[i] == a[j])
				{
					a[i] = rand() % Q + 1;
					j = i;
				}
			}
		}
		std::cout << '\n';
		for (int i = 0; i < Q; i++) //循环传递随机数到getnumber中
		{
			Riddle R1;
			R1.getnumber1 = a[i];
			R1.Game();
			system("pause");
			system("cls");
			Controller C;
			int tmp = C.Menu();//Menu函数return了一个tmp_key函数
			switch (tmp)
			{
			case 1:
			{
				system("cls");
				continue;
			}
			case 2:
			{
				return 0;
			}
			default:
				break;
			}
		}
	}
}