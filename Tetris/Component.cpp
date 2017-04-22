#include "Component.h"
Component::Component(int parentX, int parentY) : m_parentX(parentX), m_parentY(parentY){}

Component::~Component(){}

void Component::Move(Component* comp, Direction direction){
	Clean();
	switch (direction){
	case UP:
		ChangeShapeDirection(comp);
		break;
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
