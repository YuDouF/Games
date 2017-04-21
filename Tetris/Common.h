#pragma once
#include <Windows.h>
enum Direction{
	UP,
	RIGHT,
	DOWN,
	LEFT
};
static void CursorToPos(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}