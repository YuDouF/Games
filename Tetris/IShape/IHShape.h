#pragma once
#include "../Component.h"
class IHShape : public Component{
	bool m_location[1][3];
public:
	IHShape(int parentX, int parentY);
	~IHShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	void Display();
	void Clean();
private:

};