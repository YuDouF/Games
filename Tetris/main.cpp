#include "Component.h"
#include "LUpShape.h"
int main(){
	Component* lUpShape = new LUpShape(10, 10);
	lUpShape->Display();
	lUpShape->ChangeShapeDirection(lUpShape);
	lUpShape->Display();

}