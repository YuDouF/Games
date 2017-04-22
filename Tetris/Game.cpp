#include "Game.h"
#include "Timer.h"
#include "Common.h"
#include "HShape\HShape.h"
#include "IShape\IVShape.h"
#include "LShape\LUpShape.h"
#include "TShape\TUpShape.h"
#include "ZShape\ZVShape.h"
#include <iostream>

Game::Game(){
	//Òþ²Ø¹â±ê
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	srand(0);
	int current = rand() % 5;
	int next = rand() % 5;
	m_currentComponent = CreateComponent(current);
	m_nextComponent = CreateComponent(next);

	m_timer = Timer::GetInstant();
	m_timer->SetGame(this);
	m_timer->SetUpdateFunc(&Game::UpdateGame);
}
Game::~Game(){}
Component* Game::CreateComponent(int type){
	Component* com = NULL;
	switch (type){
	case HSHAPE:
		com = new HShape(5, 1);
		break;
	case ISHAPE:
		com = new IVShape(5, 1);
		break;
	case LSHAPE:
		com = new LUpShape(5, 1);
		break;
	case TSHAPE:
		com = new TUpShape(5, 1);
		break;
	case ZSHAPE:
		com = new ZVShape(5, 1);
		break;
	}
	return com;
}
void Game::DrawBorder(){
	for (int i = 1; i <= GAME_HEIGHT; ++i){
		for (int j = 1; j <= GAME_WIDTH; ++j){
			CursorToPos(j - 1, i - 1);
			if (i == 1 || i == GAME_HEIGHT){
				std::cout << "*";
			}
			else if (j == 1 || j == GAME_WIDTH){
				std::cout << "*";
			}
			else if (j > 1 && j < GAME_WIDTH){
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
void Game::StartGame(){
	DrawBorder();
	//display compoent
	m_currentComponent->Display();
	//m_timer->StartTimer();
}
void Game::ComponentMove(Direction direction){
	m_currentComponent->Move(m_currentComponent, direction);
}
void Game::Update(){

}
void Game::UpdateGame(){

}