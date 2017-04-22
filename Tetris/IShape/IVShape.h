#pragma once
#include "../Component.h"
class IVShape : public Component{
	bool m_location[3][1];
public:
	IVShape(int parentX, int parentY);
	~IVShape();
	Component* ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};