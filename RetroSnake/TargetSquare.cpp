#include "TargetSquare.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
TargetSquare::TargetSquare(int width, int height) : Square(width, height){}
void TargetSquare::CreateTargetSquare(int leftX, int rightX, int topY, int bottomY){
	srand((unsigned)time(NULL));
	while (true){
		int x = rand() % (GAME_WIDTH - 2) + 1;
		int y = rand() % (GAME_HEIGHT - 2) + 1;
		if ((x < leftX || x > rightX) && (y < topY || y > bottomY)){
			this->SetX(x);
			this->SetY(y);
			break;
		}
	}	
}
void TargetSquare::Display(){
	CursorToPos(GetX(), GetY());
	std::cout << "*";
}