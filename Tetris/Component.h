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
	std::vector<Point*> GetUpBorder(){
		std::vector<Point*> upBorder;
		Point* lfirst = new Point(m_parentX + 1, m_parentY);
		Point* lsecond = new Point(m_parentX, m_parentY + 1);
		upBorder.push_back(lfirst);
		upBorder.push_back(lsecond);

		return upBorder;
	}
	std::vector<Point*> GetLeftBorder(){

		std::vector<Point*> leftBorder;
		Point* lfirst = new Point(m_parentX + 1, m_parentY);
		Point* lsecond = new Point(m_parentX, m_parentY + 1);
		Point* lthird = new Point(m_parentX, m_parentY + 2);
		leftBorder.push_back(lfirst);
		leftBorder.push_back(lsecond);
		leftBorder.push_back(lthird);

		return leftBorder;
	}
	std::vector<Point*> GetBottomBorder(){

		std::vector<Point*> bottomLine;
		Point* bfirst = new Point(m_parentX, m_parentY + 2);
		Point* bsecond = new Point(m_parentX + 1, m_parentY + 1);
		bottomLine.push_back(bfirst);
		bottomLine.push_back(bsecond);

		return bottomLine;
	}

	std::vector<Point*> GetRightBorder(){

		std::vector<Point*> rightBorder;
		Point* rfirst = new Point(m_parentX + 1, m_parentY);
		Point* rsecond = new Point(m_parentX + 1, m_parentY + 1);
		Point* rthird = new Point(m_parentX, m_parentY + 2);
		rightBorder.push_back(rfirst);
		rightBorder.push_back(rsecond);
		rightBorder.push_back(rthird);

		return rightBorder;
	}
	
	void SetParentX(int x);
	int GetParentX();

	void SetParentY(int y);
	int GetParentY();
};