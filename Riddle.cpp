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
int totalscore = 0;//����ȫ�ֱ���totalscore
int CountLines(char *filename)
{
	ifstream ReadFile;
	int n = 0;
	string tmp;
	ReadFile.open(filename, ios::in); //ios::in ���ļ����ж�ȡ
	if (ReadFile.fail())			  //�ļ���ʧ��:����0
	{
		return 0;
	}
	else //�ļ�����
	{
		while (getline(ReadFile, tmp, '\n'))
		{
			n++;
		}
		ReadFile.close();
		return n; //n���ļ�������
	}
}

string ReadLine(char *filename, int line)
{
	int lines, i = 0;
	string temp;
	fstream file;
	file.open(filename, ios::in);
	lines = CountLines(filename); //��countlines������ȡ����
	if (line <= 0)
	{
		return "Error 1: �ⲿ�ļ��������󣬲���Ϊ0������";
	}
	if (file.fail())
	{
		return "Error 2: �ļ������ڡ�";
	}
	if (line > lines)
	{
		return "Error 3: �ⲿ�ļ����������ļ����ȡ�";
	}
	while (getline(file, temp) && i < line - 1)
	{
		i++;
	}
	file.close();
	return temp;
}

bool is_number(string str) //�ж��Ƿ���С��
{
	/*if (str.c_str()[0] == 45)
	{
		return false;
	}Ҫ���и���ʱ��*/

	for (int i = 0; i < str.length(); i++)
	{
		if (str.c_str()[i] < '0' || str.c_str()[i] > '9')
		{
			if (str.c_str()[i] == 46) //֧��С��
			{
				return true;
			}
			else
				return false;
		}
	}
}

void SetWindowSize(int cols, int lines) //���ô��ڴ�С
{
	system("title RIDDLE"); //���ô��ڱ���
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines); //һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
	system(cmd);												  //system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetCursorPosition(const int x, const int y) //���ù��λ��
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID) //�����ı���ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor() //�����ı�����ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
								FOREGROUND_BLUE |
								BACKGROUND_BLUE |
								BACKGROUND_GREEN |
								BACKGROUND_RED);
}
int Controller::Menu() //ѡ��˵�
{
	/*���Ʋ˵�*/
	SetColor(3);
	SetCursorPosition(18, 12);
	std::cout << "�˵���";
	Sleep(100);
	SetCursorPosition(17, 14);
	SetBackColor();
	std::cout << "������Ϸ";
	Sleep(100);
	SetCursorPosition(14, 16);
	SetColor(3);
	std::cout << "���ˣ�����ѧϰ����˼";
	Sleep(100);
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)//�����switch���벿����Ϊ�����ƶ���tmp_key��ת����ֻҪ���س��ͻ����whileѭ��
		{
		case 72: //UP��
			if (tmp_key > 1)
			{
				SetCursorPosition(17, 14);
				SetBackColor();
				std::cout << "������Ϸ";
				SetCursorPosition(14, 16);
				SetColor(3);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			break;

		case 80: //DOWN��
			if (tmp_key < 2)
			{
				SetCursorPosition(14, 16);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(17, 14);
				SetColor(3);
				std::cout << "������Ϸ";
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

void Riddle::Game() //��Ϸѭ��
{

	string Answer;
	int line = getnumber1;
	char filename1[] = "����.txt";
	char filename2[] = "�յ�.txt";
	char filename3[] = "��ʾ.txt";
	SetCursorPosition(10, 14);
	cout << "�ⲿ�ļ����سɹ���"
		 << " ��ȡ������ " << CountLines(filename1) << "��" << '\n';
	SetCursorPosition(14, 16);
	cout << "����ȡ����" << getnumber1 << "����Ŀ" << '\n';
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
		cout << "��������Ĵ�:";
		string str;
		while (1)
		{
			cin >> str;
			cout << '\n';
			if (is_number(str))
			{
				cout << "�벻Ҫ�������ֻ���ţ����ǲ�������Ϸ���������룺";
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
			cout << "��ϲŶ�����ڵ�" << count << "�β¶���";
			cout << '\n';
			if (count == 1)
			{
				singlescore = 10;
				totalscore = singlescore + totalscore;
				cout << "��Ŀǰ���ܷ����ǣ�" << totalscore
					 << "��С��֣�" << singlescore << '\n';
			}
			if (count > 1 && count <= 4)
			{
				singlescore = 5;
				totalscore = singlescore + totalscore;
				cout << "��Ŀǰ���ܷ����ǣ�" << totalscore
					 << "��С��֣�" << singlescore << '\n';
			}
			if (count > 4 && count < 8)
			{
				singlescore = 1;
				totalscore = singlescore + totalscore;
				cout << "��Ŀǰ���ܷ����ǣ�" << totalscore
					 << "��С��֣�" << singlescore << '\n';
			}
			if (count > 8)
			{
				singlescore = 0;
				totalscore = singlescore + totalscore;
				cout << "��Ŀǰ���ܷ����ǣ�" << totalscore
					 << "��С��֣�" << singlescore << '\n';
			}
			break;
		}
		else
		{
			cout << "�𰸴���������һ�Ρ�" << '\n';
			if (count >= 3)
			{
				cout << ReadLine(filename3, line) << '\n';
				cout << '\n';
			}
			if (count >= 10)
			{
				system("cls");
				SetCursorPosition(17, 14);
				OverInterface *Over = new OverInterface(); //��̬����һ��OverInterface��Over��new�����Ķ������á�*����.�������ʸö���ĳ�Ա�����ģ��������������->��
				Over->Action();							//��������
				SetCursorPosition(8, 17);
				cout << "���Ѿ�������ʮ���ˣ����� " << Answer << " ,�´μ���Ŷ��" << '\n';
				SetCursorPosition(15, 19);
				break;
			}
		}
	}
}
int Riddle::PlayGame()
{
	int Q = 0;
	char filename1[] = "����.txt";
	Q = CountLines(filename1);                    //Q��ֵ���������������������
	SetWindowSize(38, 32);						  //���ô��ڴ�С
	SetColor(3);								  //���ÿ�ʼ������ɫ
	StartInterface* start = new StartInterface(); //��̬����һ��StartInterface��start ʹ��new������->������
	start->Action();							  //��ʼ��������StartInterface start��start.action()��������ͬ
	SetCursorPosition(22, 25);
	std::cout << "Press any key to start... ";	  //���ùر�λ�ã��������ʾ��ȴ�������������
	SetCursorPosition(22, 26);
	system("pause");
	system("cls");

	while (1)
	{
		int a[100];
		srand((unsigned)time(NULL));
		for (int i = 0; i < Q; i++) //ѭ����������������浽a������
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
		for (int i = 0; i < Q; i++) //ѭ�������������getnumber��
		{
			Riddle R1;
			R1.getnumber1 = a[i];
			R1.Game();
			system("pause");
			system("cls");
			Controller C;
			int tmp = C.Menu();//Menu����return��һ��tmp_key����
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