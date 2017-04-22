#include "TDownShape.h"
#include "TLeftShape.h"
#include "../Common.h"
#include <iostream>
TDownShape::TDownShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = false;
	m_location[0][1] = true;
	m_location[0][2] = false;
	m_location[1][0] = true;
	m_location[1][1] = true;
	m_location[1][0] = true;
}
TDownShape::~TDownShape(){}
void TDownShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	Clean();
	delete shapeDirection;

	shapeDirection = new TLeftShape(parentX, parentY);
}
void TDownShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void TDownShape::Clean(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}