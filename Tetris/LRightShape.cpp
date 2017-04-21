#include "LRightShape.h"
#include <iostream>
LRightShape::LRightShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[0][2] = true;
	m_location[1][0] = true;
	m_location[1][1] = false;
	m_location[1][2] = false;
}
LRightShape::~LRightShape(){}
Component* LRightShape::ChangeShapeDirection(Component*& ShapeDirection){
	return NULL;
}
void LRightShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 3; ++x){
			if (m_location[y][x]){
				CursorToPos(m_parentX + x, m_parentY + y);
				std::cout << "*";
			}
		}
	}
}