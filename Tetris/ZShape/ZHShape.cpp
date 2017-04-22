#include "ZHShape.h"
#include "ZVShape.h"
#include "../Common.h"
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