#pragma once
#include "../Component.h"
class LUpShape : public Component{
	bool m_location[3][2];
public:
	LUpShape(int parentX, int parentY);
	~LUpShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
};
