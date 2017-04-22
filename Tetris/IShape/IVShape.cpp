#include "IVShape.h"
#include "IHShape.h"
#include "../Common.h"
#include <iostream>
IVShape::IVShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[1][0] = true;
	m_location[2][0] = true;
}
IVShape::~IVShape(){}
Component* IVShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	Clean();
	delete shapeDirection;

	shapeDirection = new IHShape(--parentX, parentY);
	return shapeDirection;
}
void IVShape::Display(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 1; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void IVShape::Clean(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 1; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}