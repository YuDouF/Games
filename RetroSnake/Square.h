#pragma once
#include "common.h"
class Square {
private:
	int m_X;
	int m_Y;
	int m_width;
	int m_height;
public:
	Square(int width, int height);
	Square(int X, int Y, int width, int height);
	Square(const Square& s);
	int GetWidth();
	int GetHeight();

	int GetX();
	void SetX(int X);

	int GetY();
	void SetY(int Y);
};