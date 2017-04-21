#include "LUpShape.h"
#include "LRightShape.h"
#include "Common.h"
#include <iostream>
LUpShape::LUpShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = false;
	m_location[1][0] = true;
	m_location[1][1] = false;
	m_location[2][0] = true;
	m_location[2][1] = true;
}
LUpShape::~LUpShape(){}
Component* LUpShape::ChangeShapeDirection(Component*& shapeDirection){
	delete shapeDirection;
	shapeDirection = new LRightShape(m_parentX, m_parentY);

	return shapeDirection;
}
void LUpShape::Display(){
	for (int y = 0; y < 3; ++y){
		for (int x = 0; x < 2; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}