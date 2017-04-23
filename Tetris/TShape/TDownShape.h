#pragma once
#include "../Component.h"
class TDownShape : public Component{
	bool m_location[2][3];
public:
	TDownShape(int parentX, int parentY);
	~TDownShape();
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
