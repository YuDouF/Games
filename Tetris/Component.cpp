#include "Component.h"
Component::Component(int parentX, int parentY) : m_parentX(parentX), m_parentY(parentY){}
Component::Component(Direction direction) : m_direction(direction){}
Component::~Component(){}
Component* Component::ChangeShapeDirection(Component*& shapeDirection){
	return NULL;
}
void Component::Move(Direction direction){
	switch (direction){
	case RIGHT:
		++m_parentX;
		break;
	case DOWN:
		++m_parentY;
		break;
	case LEFT:
		--m_parentX;
		break;
	}
}
void Component::Display(){}
void Component::SetDirection(Direction direction){
	m_direction = direction;
}
Direction Component::GetDirection(){
	return m_direction;
}