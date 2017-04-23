#pragma once
#include "../Component.h"
class TRightShape : public Component{
	bool m_location[2][3];
public:
	TRightShape(int parentX, int parentY);
	~TRightShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	void Display();
	void Clean();
private:

};
