#pragma once
#include "../Component.h"
class IHShape : public Component{
	bool m_location[1][3];
public:
	IHShape(int parentX, int parentY);
	~IHShape();
	Component* ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};