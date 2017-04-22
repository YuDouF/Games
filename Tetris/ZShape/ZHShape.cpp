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
std::vector<Point*> ZHShape::GetBottomLine(){
	std::vector<Point*> bottomLine;
	Point* first = new Point(m_parentX, m_parentY);
	Point* second = new Point(m_parentX + 1, m_parentY + 1);
	Point* third = new Point(m_parentX + 2, m_parentY + 1);
	bottomLine.push_back(first);
	bottomLine.push_back(second);
	bottomLine.push_back(third);

	return bottomLine;
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