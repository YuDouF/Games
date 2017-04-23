#include "IHShape.h"
#include "IVShape.h"
#include "../Common.h"
#include <iostream>
IHShape::IHShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[0][2] = true;
}
IHShape::~IHShape(){}
void IHShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	//Clean();
	delete shapeDirection;

	shapeDirection = new IVShape(++parentX, parentY);
}
std::vector<Point*> IHShape::GetUpBorder(){
	std::vector<Point*> upBorder;
	Point* lfirst = new Point(m_parentX, m_parentY);
	Point* lsecond = new Point(m_parentX + 1, m_parentY);
	Point* lthird = new Point(m_parentX + 2, m_parentY);
	upBorder.push_back(lfirst);
	upBorder.push_back(lsecond);
	upBorder.push_back(lthird);

	return upBorder;
}
std::vector<Point*> IHShape::GetLeftBorder(){

	std::vector<Point*> leftBorder;
	Point* lfirst = new Point(m_parentX - 1, m_parentY);
	leftBorder.push_back(lfirst);

	return leftBorder;
}
std::vector<Point*> IHShape::GetBottomBorder(){

	std::vector<Point*> bottomLine;
	Point* bfirst = new Point(m_parentX, m_parentY + 1);
	Point* bsecond = new Point(m_parentX + 1, m_parentY + 1);
	Point* bthird = new Point(m_parentX + 2, m_parentY + 1);
	bottomLine.push_back(bfirst);
	bottomLine.push_back(bsecond);
	bottomLine.push_back(bthird);

	return bottomLine;
}

std::vector<Point*> IHShape::GetRightBorder(){

	std::vector<Point*> rightBorder;
	Point* rfirst = new Point(m_parentX + 2 + 1, m_parentY);
	rightBorder.push_back(rfirst);

	return rightBorder;
}
void IHShape::Display(){
	for (int y = 0; y < 1; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void IHShape::Clean(){
	for (int y = 0; y < 1; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}