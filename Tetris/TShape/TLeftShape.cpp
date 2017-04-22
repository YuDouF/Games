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
	Clean();
	delete shapeDirection;

	shapeDirection = new TUpShape(parentX, parentY);
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