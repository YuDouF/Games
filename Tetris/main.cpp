#include "Component.h"
#include "LUpShape.h"
#include "LRightShape.h"
#include <iostream>

int main(){
	Component* lShape = new LUpShape(10, 10);
	lShape->Display();
	lShape->ChangeShapeDirection(lShape);
	lShape->Display();

	std::cin.get();
}