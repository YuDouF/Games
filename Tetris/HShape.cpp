#include "HShape.h"
#include "Common.h"
#include <iostream>
HShape::HShape(int parentX, int parentY) : Component(parentX, parentY){
	m_location[0][0] = true;
	m_location[0][1] = true;
	m_location[1][0] = true;
	m_location[1][1] = true;
}
HShape::~HShape(){}
void HShape::Display(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 2; ++x){
			CursorToPos(m_parentX + x, m_parentY + y);
			std::cout << "*";
		}
	}
}
void HShape::Clean(){
	for (int y = 0; y < 2; ++y){
		for (int x = 0; x < 2; ++x){
			CursorToPos(m_parentX + x, m_parentY + y);
			std::cout << " ";
		}
	}
}