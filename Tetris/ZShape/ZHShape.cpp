#include "ZHShape.h"
#include "ZVShape.h"
#include "../Common.h"
#include "../Point.h"
#include <iostream>
ZHShape::ZHShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[0][2] = false;
	m_location[1][0] = false;
	m_location[1][1] = true;
	m_location[1][2] = true;
}
ZHShape::~ZHShape(){}
void ZHShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	delete shapeDirection;
	
	shapeDirection = new ZVShape(parentX, parentY);
}
std::vector<Point*> ZHShape::GetUpBorder(){
	std::vector<Point*> upBorder;
	Point* lfirst = new Point(m_parentX, m_parentY);
	Point* lsecond = new Point(m_parentX + 1, m_parentY);
	Point* lthird = new Point(m_parentX + 2, m_parentY + 1);
	upBorder.push_back(lfirst);
	upBorder.push_back(lsecond);
	upBorder.push_back(lthird);

	return upBorder;
}
std::vector<Point*> ZHShape::GetLeftBorder(){

	std::vector<Point*> leftBorder;
	Point* lfirst = new Point(m_parentX - 1, m_parentY);
	Point* lsecond = new Point(m_parentX + 1 - 1, m_parentY + 1);
	leftBorder.push_back(lfirst);
	leftBorder.push_back(lsecond);

	return leftBorder;
}
std::vector<Point*> ZHShape::GetBottomBorder(){

	std::vector<Point*> bottomLine;
	Point* bfirst = new Point(m_parentX, m_parentY + 1);
	Point* bsecond = new Point(m_parentX + 1, m_parentY + 1 + 1);
	Point* bthird = new Point(m_parentX + 2, m_parentY + 1 + 1);
	bottomLine.push_back(bfirst);
	bottomLine.push_back(bsecond);
	bottomLine.push_back(bthird);

	return bottomLine;
}

std::vector<Point*> ZHShape::GetRightBorder(){

	std::vector<Point*> rightBorder;
	Point* rfirst = new Point(m_parentX + 1 + 1, m_parentY);
	Point* rsecond = new Point(m_parentX + 2 + 1, m_parentY + 1);
	rightBorder.push_back(rfirst);
	rightBorder.push_back(rsecond);

	return rightBorder;
}
void ZHShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void ZHShape::Clean(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}