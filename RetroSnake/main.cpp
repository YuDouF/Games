#include "Game.h"
#include "Snake.h"
#include <conio.h>

int main(){
	Snake* snake = new Snake(10, 5, 3);
	Game* game = new Game(snake);
	game->StartGame();

	char ch;
	ch = getch();
	while (ch = getch()){
		if (ch != -32){
			snake->SetHeadDirecte(Directe(ch));
		}
	}
}