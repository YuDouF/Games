#pragma once
#include <Windows.h>
const int GAME_WIDTH = 40;
const int GAME_HEIGHT = 20;
enum Directe{
	UP = 72,
	RIGHT = 77,
	DOWN = 80,
	LEFT = 75
};
static void CursorToPos(int x, int y){
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}