#include "IHShape.h"
#include "IVShape.h"
#include "../Common.h"
#include <iostream>
IHShape::IHShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[0][2] = true;
}
IHShape::~IHShape(){}
Component* IHShape::ChangeShapeDirection(Component*& shapeDirection){
	int parentX = m_parentX;
	int parentY = m_parentY;
	Clean();
	delete shapeDirection;

	shapeDirection = new IVShape(++parentX, parentY);
	return shapeDirection;
}
void IHShape::Display(){
	for (int y = 0; y < 1; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}
void IHShape::Clean(){
	for (int y = 0; y < 1; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << " ";
			}
		}
	}
}