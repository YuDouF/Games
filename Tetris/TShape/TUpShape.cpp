#include "TUpShape.h"
#include "TRightShape.h"
#include "../Common.h"
#include <iostream>
TUpShape::TUpShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[0][2] = true;
	m_location[1][0] = false;
	m_location[1][1] = true;
	m_location[1][2] = false;
}
TUpShape::~TUpShape(){}
Component* TUpShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	Clean();
	delete shapeDirection;
	
	shapeDirection = new TRightShape(parentX, parentY);
	return shapeDirection;
}
void TUpShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void TUpShape::Clean(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}