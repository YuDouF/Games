#pragma once
#include "../Component.h"
class LRightShape : public Component{
	bool m_location[2][3];
public:
	LRightShape(int parentX, int parentY);
	~LRightShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
