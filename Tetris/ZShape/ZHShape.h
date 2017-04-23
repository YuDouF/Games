#pragma once
#include "../Component.h"
class Point;
class ZHShape : public Component{
	bool m_location[2][3];
public:
	ZHShape(int parentX, int parentY);
	~ZHShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	void Display();
	void Clean();
};
