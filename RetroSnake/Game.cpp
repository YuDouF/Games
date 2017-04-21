#include "Game.h"
#include "Snake.h"
#include "TargetSquare.h"
#include "Timer.h"
#include "common.h"
#include <iostream>

Game::Game(Snake* snake) : m_snake(snake), m_target(NULL){
	//Òþ²Ø¹â±ê
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	m_timer = Timer::GetInstant();
	m_timer->SetGame(this);
	m_timer->SetUpdateFunc(&Game::UpdateGame);
}
Game::~Game(){}
void Game::SetSnake(Snake* snake){
	m_snake = snake;
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
void Game::CreateTarget(){
	int leftX, rightX, topY, bottomY;
	m_snake->GetRange(leftX, rightX, topY, bottomY);
	m_target = new TargetSquare(1, 0);
	m_target->CreateTargetSquare(leftX, rightX, topY, bottomY);
}
void Game::StartGame(){
	DrawBorder();
	CreateTarget();
	//display snake
	for (std::deque<Square*>::iterator it = m_snake->GetList().begin(); it != m_snake->GetList().end(); ++it){
		CursorToPos((*it)->GetX(), (*it)->GetY());
		std::cout << "*";
	}

	m_target->Display();
	m_timer->StartTimer();
}
bool Game::IsOver(){
	int x = m_snake->GetHeadX();
	int y = m_snake->GetHeadY();
	if (x == 0 || x == GAME_WIDTH - 1 || y == 0 || y == GAME_HEIGHT - 1 || m_snake->IsCrash()){
		return true;
	}
	return false;
}
bool Game::IsEat(){
	if (m_snake->GetHeadX() == m_target->GetX() && m_snake->GetHeadY() == m_target->GetY()){
		return true;
	}
	return false;
}
void Game::Update(){
	m_snake->Clean();
	if (IsEat()){
		m_snake->AddSquareToTail();
		UpdateTarget();
		m_target->Display();
		m_timer->SpeedUp();
	}
	m_snake->Display();
}
void Game::UpdateTarget(){
	int leftX, rightX, topY, bottomY;
	m_snake->GetRange(leftX, rightX, topY, bottomY);
	m_target->CreateTargetSquare(leftX, rightX, topY, bottomY);
}
void Game::UpdateGame(){
	m_snake->Move();
	Update();
	if (IsOver()){
		m_timer->StopTimer();
		std::cout << "Game Over!!\n";
		return;
	}
}