#pragma once
#include "../Component.h"
class LLeftShape : public Component{
	bool m_location[2][3];
public:
	LLeftShape(int parentX, int parentY);
	~LLeftShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	void Display();
	void Clean();
private:

};
