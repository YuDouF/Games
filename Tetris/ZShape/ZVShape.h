#pragma once
#include "../Component.h"
class Border;
class ZVShape : public Component{
	bool m_location[3][2];
public:
	ZVShape(int parentX, int parentY);
	~ZVShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();

	void Display();
	void Clean();
private:

};
