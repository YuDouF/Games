#pragma once
#include "../Component.h"
class IVShape : public Component{
	bool m_location[3][1];
public:
	IVShape(int parentX, int parentY);
	~IVShape();
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