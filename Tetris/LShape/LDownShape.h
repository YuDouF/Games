#pragma once
#include "../Component.h"
class LDownShape : public Component{
	bool m_location[3][2];
public:
	LDownShape(int parentX, int parentY);
	~LDownShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	//std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	std::vector<Point*> GetLocation() const;

	void Display();
	void Clean();
private:

};
