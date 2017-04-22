#include "TRightShape.h"
#include "TDownShape.h"
#include "../Common.h"
#include <iostream>
TRightShape::TRightShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = false;
	m_location[0][1] = true;
	m_location[1][0] = true;
	m_location[1][1] = true;
	m_location[2][0] = false;
	m_location[2][1] = true;
}
TRightShape::~TRightShape(){}
Component* TRightShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	Clean();
	delete shapeDirection;

	shapeDirection = new TDownShape(parentX, parentY);
	return shapeDirection;
}
void TRightShape::Display(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void TRightShape::Clean(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}