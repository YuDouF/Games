#pragma once
#include <deque>
#include "common.h"
class Square;
class Snake{
public:
	Snake(int x, int y, int length);
	int GetHeadX();
	int GetHeadY();
	void SetHeadDirecte(Directe directe);
	Directe GetHeadDirecte();
	Directe GetTailDirecte();
	void AddSquareToTail();
	void Move();
	std::deque<Square*>& GetList();
	void GetRange(int& leftX, int& rightX, int& topY, int& bottomY);
	void Clean();
	void Display();
	bool IsCrash();
private:
	int m_headX;
	int m_headY;
	int m_length;
	std::deque<Square*> m_sList;
	Directe m_headDirect;
	Directe m_tailDirect;
};