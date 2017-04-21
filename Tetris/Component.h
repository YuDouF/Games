#pragma once
#include "Common.h"
class Component{
protected:
	int m_parentX, m_parentY;
	Direction m_direction;
public:
	Component(int parentX, int parentY);
	Component(Direction direction);
	virtual ~Component();
	virtual Component* ChangeShapeDirection(Component*& shapeDirection);
	void Move(Direction direction);
	virtual void Display();
	void SetDirection(Direction direction);
	Direction GetDirection();

};