#include "Component.h"
Component::Component(int parentX, int parentY) : m_parentX(parentX), m_parentY(parentY){}

Component::~Component(){}

void Component::Move(Component*& comp, Direction direction){
	Clean();
	if (direction == UP){
		comp->ChangeShapeDirection(comp);
		comp->Display();
	}
	else{
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
		Display();
	}
}
void Component::SetParentX(int x){
	m_parentX = x;
}
int Component::GetParentX(){
	return m_parentX;
}
void Component::SetParentY(int y){
	m_parentY = y;
}
int Component::GetParentY(){
	return m_parentY;
}