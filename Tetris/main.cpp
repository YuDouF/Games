#include "Component.h"
#include "LShape\LUpShape.h"
#include "TShape\TUpShape.h"
#include "IShape\IHShape.h"
#include "ZShape\ZVShape.h"
#include "HShape.h"
#include <iostream>

int main(){
	Component* lShape = new LUpShape(10, 10);
	lShape->Display();
	lShape->ChangeShapeDirection(lShape);
	lShape->Display();

	Component* TShape = new TUpShape(5, 5);
	TShape->Display();
	TShape->ChangeShapeDirection(TShape);
	TShape->Display();

	Component* IShape = new IHShape(3, 3);
	IShape->Display();
	IShape->ChangeShapeDirection(IShape);
	IShape->Display();

	Component* ZShape = new ZVShape(30, 30);
	ZShape->Display();
	ZShape->ChangeShapeDirection(ZShape);
	ZShape->Display();

	Component* shape = new HShape(20, 20);
	shape->Display();


	std::cin.get();
}