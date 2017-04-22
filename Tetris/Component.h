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
	virtual void Display();

	void Move(Direction direction);
	void SetDirection(Direction direction);
	Direction GetDirection();

};