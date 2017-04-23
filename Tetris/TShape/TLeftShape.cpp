#include "TLeftShape.h"
#include "TUpShape.h"
#include "../Common.h"
#include <iostream>
TLeftShape::TLeftShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = false;
	m_location[1][0] = true;
	m_location[1][1] = true;
	m_location[2][0] = true;
	m_location[2][1] = false;
}
TLeftShape::~TLeftShape(){}
void TLeftShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	//Clean();
	delete shapeDirection;

	shapeDirection = new TUpShape(parentX, parentY);
}
//std::vector<Point*> TLeftShape::GetUpBorder(){
//	std::vector<Point*> upBorder;
//	Point* lfirst = new Point(m_parentX, m_parentY);
//	Point* lsecond = new Point(m_parentX + 1, m_parentY + 1);
//	upBorder.push_back(lfirst);
//	upBorder.push_back(lsecond);
//
//	return upBorder;
//}
std::vector<Point*> TLeftShape::GetLeftBorder(){

	std::vector<Point*> leftBorder;
	Point* lfirst = new Point(m_parentX - 1, m_parentY);
	Point* lsecond = new Point(m_parentX - 1, m_parentY + 1);
	Point* lthird = new Point(m_parentX - 1, m_parentY + 2);
	leftBorder.push_back(lfirst);
	leftBorder.push_back(lsecond);
	leftBorder.push_back(lthird);

	return leftBorder;
}
std::vector<Point*> TLeftShape::GetBottomBorder(){

	std::vector<Point*> bottomLine;
	Point* bfirst = new Point(m_parentX, m_parentY + 2 + 1);
	Point* bsecond = new Point(m_parentX + 1, m_parentY + 1 + 1);
	bottomLine.push_back(bfirst);
	bottomLine.push_back(bsecond);

	return bottomLine;
}

std::vector<Point*> TLeftShape::GetRightBorder(){

	std::vector<Point*> rightBorder;
	Point* rfirst = new Point(m_parentX + 1, m_parentY);
	Point* rsecond = new Point(m_parentX + 1 + 1, m_parentY + 1);
	Point* rthird = new Point(m_parentX + 1, m_parentY + 2);
	rightBorder.push_back(rfirst);
	rightBorder.push_back(rsecond);
	rightBorder.push_back(rthird);

	return rightBorder;
}
std::vector<Point*> TLeftShape::GetLocation() const{
	std::vector<Point*> temp;
	temp.push_back(new Point(m_parentX, m_parentY));
	temp.push_back(new Point(m_parentX, m_parentY + 1));
	temp.push_back(new Point(m_parentX + 1, m_parentY + 1));
	temp.push_back(new Point(m_parentX, m_parentY + 2));

	return temp;
}
void TLeftShape::Display(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void TLeftShape::Clean(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}