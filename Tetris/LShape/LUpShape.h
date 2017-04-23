#pragma once
#include "../Component.h"
class LUpShape : public Component{
	bool m_location[3][2];
public:
	LUpShape(int parentX, int parentY);
	~LUpShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	void Display();
	void Clean();
};
