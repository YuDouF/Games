#pragma once
#include "Common.h"
class Component{
protected:
	int m_parentX, m_parentY;
public:
	Component(int parentX, int parentY);
	virtual ~Component();
	virtual void ChangeShapeDirection(Component*& shapeDirection) = 0;
	virtual void Display() = 0;
	virtual void Clean() = 0;

	void Move(Component*& comp, Direction direction);
};