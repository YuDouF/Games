#pragma once
#include "../Component.h"
class Point;
class ZHShape : public Component{
	bool m_location[2][3];
public:
	ZHShape(int parentX, int parentY);
	~ZHShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetBottomLine();
	void Display();
	void Clean();
};
