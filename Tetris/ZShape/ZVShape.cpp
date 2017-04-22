#include "ZVShape.h"
#include "ZHShape.h"
#include "../Common.h"
#include <iostream>
ZVShape::ZVShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = false;
	m_location[0][1] = true;
	m_location[1][0] = true;
	m_location[1][1] = true;
	m_location[2][0] = true;
	m_location[2][1] = false;
}
ZVShape::~ZVShape(){}
Component* ZVShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	Clean();
	delete shapeDirection;

	shapeDirection = new ZHShape(parentX, parentY);
	return shapeDirection;
}
void ZVShape::Display(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void ZVShape::Clean(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}