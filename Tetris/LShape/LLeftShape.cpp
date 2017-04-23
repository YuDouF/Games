#include "LLeftShape.h"
#include "LUpShape.h"
#include "../Common.h"
#include <iostream>
LLeftShape::LLeftShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = false;
	m_location[0][1] = false;
	m_location[0][2] = true;
	m_location[1][0] = true;
	m_location[1][1] = true;
	m_location[1][2] = true;
}
LLeftShape::~LLeftShape(){}
void LLeftShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	//Clean();
	delete shapeDirection;

	shapeDirection = new LUpShape(parentX, parentY);
}
//std::vector<Point*> LLeftShape::GetUpBorder(){
//	std::vector<Point*> upBorder;
//	Point* lfirst = new Point(m_parentX, m_parentY + 1);
//	Point* lsecond = new Point(m_parentX + 1, m_parentY + 1);
//	Point* lthird = new Point(m_parentX + 2, m_parentY);
//	upBorder.push_back(lfirst);
//	upBorder.push_back(lsecond);
//	upBorder.push_back(lthird);
//
//	return upBorder;
//}
std::vector<Point*> LLeftShape::GetLeftBorder(){

	std::vector<Point*> leftBorder;
	Point* lfirst = new Point(m_parentX + 2 - 1, m_parentY);
	Point* lsecond = new Point(m_parentX - 1, m_parentY + 1);
	leftBorder.push_back(lfirst);
	leftBorder.push_back(lsecond);

	return leftBorder;
}
std::vector<Point*> LLeftShape::GetBottomBorder(){

	std::vector<Point*> bottomLine;
	Point* bfirst = new Point(m_parentX, m_parentY + 1 + 1);
	Point* bsecond = new Point(m_parentX + 1, m_parentY + 1 + 1);
	Point* bthird = new Point(m_parentX + 2, m_parentY + 1 + 1);
	bottomLine.push_back(bfirst);
	bottomLine.push_back(bsecond);
	bottomLine.push_back(bthird);

	return bottomLine;
}

std::vector<Point*> LLeftShape::GetRightBorder(){

	std::vector<Point*> rightBorder;
	Point* rfirst = new Point(m_parentX + 2 + 1, m_parentY);
	Point* rsecond = new Point(m_parentX + 2 + 1, m_parentY + 1);
	Point* rthird = new Point(m_parentX + 2 + 1, m_parentY + 2);
	rightBorder.push_back(rfirst);
	rightBorder.push_back(rsecond);
	rightBorder.push_back(rthird);

	return rightBorder;
}
std::vector<Point*> LLeftShape::GetLocation() const{
	std::vector<Point*> temp;
	temp.push_back(new Point(m_parentX + 2, m_parentY));
	temp.push_back(new Point(m_parentX, m_parentY + 1));
	temp.push_back(new Point(m_parentX + 1, m_parentY + 1));
	temp.push_back(new Point(m_parentX + 2, m_parentY + 1));

	return temp;
}
void LLeftShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void LLeftShape::Clean(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}