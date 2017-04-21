#pragma once
#include "Square.h"
#include "common.h"
class TargetSquare : public Square{
public:
	TargetSquare(int width, int height);
	void CreateTargetSquare(int leftX, int rightX, int topY, int bottomY);
	void Display();
};