#pragma once
#include "../Component.h"
class LLeftShape : public Component{
	bool m_location[2][3];
public:
	LLeftShape(int parentX, int parentY);
	~LLeftShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
