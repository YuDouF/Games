#pragma once
#include "../Component.h"
class ZHShape : public Component{
	bool m_location[2][3];
public:
	ZHShape(int parentX, int parentY);
	~ZHShape();
	Component* ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
};
