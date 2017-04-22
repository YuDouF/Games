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
	srand(time(0));
	int current = rand() % 5;
	int next = rand() % 5;
	m_currentComponent = new ZVShape(36, 15);
	m_nextComponent = new ZVShape(20, 10);
	for (int i = 0; i < GAME_WIDTH; ++i){
		m_bottomLine[i] = GAME_HEIGHT - 1;
	}
	std::vector<int> leftLine;
	std::vector<int> rightLine;

	for (int i = 0; i < GAME_HEIGHT; ++i){
		leftLine.push_back(0);
	}
	for (int i = 0; i < GAME_HEIGHT; ++i){
		rightLine.push_back(GAME_WIDTH);
	}
	m_VLine.push_back(leftLine);
	m_VLine.push_back(rightLine);
	/*m_timer = Timer::GetInstant();
	m_timer->SetGame(this);
	m_timer->SetUpdateFunc(&Game::UpdateGame);*/
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
		com = new ZVShape(20, 15);
		break;
	}
	return com;
}
void Game::DrawBorder(){
	for (int i = 0; i <= GAME_HEIGHT; ++i){
		for (int j = 0; j <= GAME_WIDTH; ++j){
			CursorToPos(j, i);
			if (i == 0 || i == GAME_HEIGHT){
				std::cout << "*";
			}
			else if (j == 0 || j == GAME_WIDTH){
				std::cout << "*";
			}
			else if (j > 0 && j < GAME_WIDTH){
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
	if (!StopComponent(direction)){
		m_currentComponent->Move(m_currentComponent, direction);
	}
	else if (direction == DOWN){
		UpdataBorder();
		m_currentComponent = m_nextComponent;
		m_nextComponent = new ZVShape(20, 1);
	}
}
bool Game::StopComponent(Direction direction){
	std::vector<Point*> border;
	if (direction == DOWN){
		border = m_currentComponent->GetBottomBorder();
		for (std::vector<Point*>::iterator it = border.begin(); it != border.end(); ++it){
			Point* point = (*it);
			if (m_bottomLine[point->GetX() - 1] == point->GetY()){
				return true;
			}
		}
	}
	else{
		for (std::vector<std::vector<int>>::iterator it = m_VLine.begin(); it != m_VLine.end(); ++it){
			border = m_currentComponent->GetRightBorder();
			for (std::vector<Point*>::iterator i = border.begin(); i != border.end(); ++i){
				Point* point = (*i);
				if (it->at(point->GetY() - 1) == point->GetX()){
					return true;
				}
			}
			border = m_currentComponent->GetLeftBorder();
			for (std::vector<Point*>::iterator i = border.begin(); i != border.end(); ++i){
				Point* point = (*i);
				if (it->at(point->GetY() - 1) == point->GetX()){
					return true;
				}
			}
		}
	}

	return false;
}
void Game::UpdataBorder(){
	std::vector<Point*> border = m_currentComponent->GetUpBorder();
	for (std::vector<Point*>::iterator it = border.begin(); it != border.end(); ++it){
		Point* point = (*it);
		m_bottomLine[point->GetX() - 1] = point->GetY();
	}
}
void Game::Update(){

}
void Game::UpdateGame(){

}