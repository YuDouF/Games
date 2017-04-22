#pragma once
#include "../Component.h"
class TRightShape : public Component{
	bool m_location[2][3];
public:
	TRightShape(int parentX, int parentY);
	~TRightShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	void Display();
	void Clean();
private:

};
