#include "Component.h"
#include "LShape\LUpShape.h"
#include "TShape\TUpShape.h"
#include "IShape\IHShape.h"
#include "ZShape\ZVShape.h"
#include "HShape\HShape.h"
#include "Game.h"
#include <conio.h>
#include <iostream>

int main(){
	Game* game = new Game();
	game->StartGame();

	char ch;
	ch = getch();
	while (ch = getch()){
		if (ch != -32){
			game->ComponentMove(Direction(ch));
		}
	}
}