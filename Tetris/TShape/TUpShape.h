#pragma once
#include "../Component.h"
class TUpShape : public Component{
	bool m_location[2][3];
public:
	TUpShape(int parentX, int parentY);
	~TUpShape();
	Component* ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
};
