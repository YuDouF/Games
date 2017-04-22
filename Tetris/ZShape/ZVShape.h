#pragma once
#include "../Component.h"
class ZVShape : public Component{
	bool m_location[3][2];
public:
	ZVShape(int parentX, int parentY);
	~ZVShape();
	Component* ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
