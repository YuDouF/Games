#pragma once
#include "../Component.h"
class TDownShape : public Component{
	bool m_location[2][3];
public:
	TDownShape(int parentX, int parentY);
	~TDownShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
