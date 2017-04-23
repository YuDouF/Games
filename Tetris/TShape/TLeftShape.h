#pragma once
#include "../Component.h"
class TLeftShape : public Component{
	bool m_location[2][3];
public:
	TLeftShape(int parentX, int parentY);
	~TLeftShape();
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
