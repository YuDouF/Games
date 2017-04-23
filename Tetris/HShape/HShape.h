#pragma once
#include "../Component.h"
class HShape : public Component{
	bool m_location[2][2];
public:
	HShape(int parentX, int parentY);
	~HShape();
	void ChangeShapeDirection(Component*& shapeDirection);
	//std::vector<Point*> GetUpBorder();
	std::vector<Point*> GetLeftBorder();
	std::vector<Point*> GetBottomBorder();
	std::vector<Point*> GetRightBorder();
	std::vector<Point*> GetLocation() const;

	void Display();
	void Clean();
};
