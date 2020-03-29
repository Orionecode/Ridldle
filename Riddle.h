#pragma once
#include <iostream>
void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor();
class Riddle
{
private:
public:
	void Game();
	int PlayGame();
	int getnumber1;
};
class Controller
{
public:
    int Menu();
private:
};
