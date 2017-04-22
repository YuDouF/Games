#pragma once
#include "../Component.h"
class HShape : public Component{
	bool m_location[2][2];
public:
	HShape(int parentX, int parentY);
	~HShape();
	Component* ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
};
