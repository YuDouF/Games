#pragma once
#include "../Component.h"
class TLeftShape : public Component{
	bool m_location[2][3];
public:
	TLeftShape(int parentX, int parentY);
	~TLeftShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
