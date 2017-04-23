#pragma once
#include "Common.h"
#include <vector>
#include "Point.h"
class Component{
protected:
	int m_parentX, m_parentY;
public:
	Component(int parentX, int parentY);
	virtual ~Component();
	virtual void ChangeShapeDirection(Component*& shapeDirection) = 0;
	//-----------
	virtual void Display() = 0;
	virtual void Clean() = 0;
	void Move(Component*& comp, Direction direction);
	//virtual std::vector<Point*> GetUpBorder() = 0;
	virtual std::vector<Point*> GetLeftBorder() = 0;
	virtual std::vector<Point*> GetBottomBorder() = 0;
	virtual std::vector<Point*> GetRightBorder() = 0;
	virtual std::vector<Point*> GetLocation() const = 0;
	
	void SetParentX(int x);
	int GetParentX();

	void SetParentY(int y);
	int GetParentY();
};