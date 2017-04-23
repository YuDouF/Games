#pragma once
#include "../Component.h"
class LRightShape : public Component{
	bool m_location[2][3];
public:
	LRightShape(int parentX, int parentY);
	~LRightShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	void Display();
	void Clean();
private:

};
