#pragma once
#include "../Component.h"
class LDownShape : public Component{
	bool m_location[3][2];
public:
	LDownShape(int parentX, int parentY);
	~LDownShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
