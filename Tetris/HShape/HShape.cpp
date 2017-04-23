#include "HShape.h"
#include "../Common.h"
#include <iostream>
HShape::HShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[1][0] = true;
	m_location[1][1] = true;
}
HShape::~HShape(){}
void HShape::ChangeShapeDirection(Component*& shapeDirection){
}
std::vector<Point*> HShape::GetUpBorder(){
	std::vector<Point*> upBorder;
	Point* lfirst = new Point(m_parentX, m_parentY);
	Point* lsecond = new Point(m_parentX + 1, m_parentY);
	upBorder.push_back(lfirst);
	upBorder.push_back(lsecond);

	return upBorder;
}
std::vector<Point*> HShape::GetLeftBorder(){

	std::vector<Point*> leftBorder;
	Point* lfirst = new Point(m_parentX - 1, m_parentY);
	Point* lsecond = new Point(m_parentX - 1, m_parentY + 1);
	leftBorder.push_back(lfirst);
	leftBorder.push_back(lsecond);

	return leftBorder;
}
std::vector<Point*> HShape::GetBottomBorder(){

	std::vector<Point*> bottomLine;
	Point* bfirst = new Point(m_parentX, m_parentY + 1 + 1);
	Point* bsecond = new Point(m_parentX + 1, m_parentY + 1 + 1);
	bottomLine.push_back(bfirst);
	bottomLine.push_back(bsecond);

	return bottomLine;
}

std::vector<Point*> HShape::GetRightBorder(){

	std::vector<Point*> rightBorder;
	Point* rfirst = new Point(m_parentX + 1 + 1, m_parentY);
	Point* rsecond = new Point(m_parentX + 1 + 1, m_parentY + 1);
	rightBorder.push_back(rfirst);
	rightBorder.push_back(rsecond);

	return rightBorder;
}
void HShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 2; ++x){
			CursorToPos(m_parentX + x, m_parentY + y);
			std::cout << "*";
		}
	}
}
void HShape::Clean(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 2; ++x){
			CursorToPos(m_parentX + x, m_parentY + y);
			std::cout << " ";
		}
	}
}