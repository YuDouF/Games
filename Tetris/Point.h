#pragma once
class Point{
public:
	Point(int x, int y);
	~Point();
	void SetX(int x);
	int GetX();

	void SetY(int y);
	int GetY();
public:
	int m_x;
	int m_y;
};