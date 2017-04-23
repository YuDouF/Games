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
	SHAPETYPE type = SHAPETYPE(rand() & 5);
	m_currentComponent = CreateComponent(type);
	type = SHAPETYPE(rand() & 5);
	m_nextComponent = CreateComponent(type);

	std::map<int, bool> bottomLine;
	for (int i = 0; i < GAME_WIDTH; ++i){
		bottomLine.insert(std::pair<int, bool>(i, false));
	}
	std::map<int, bool> leftLine;
	for (int i = 0; i < GAME_HEIGHT; ++i){
		leftLine.insert(std::pair<int, bool>(i, false));
	}
	std::map<int, bool> rightLine;
	for (int i = 0; i < GAME_HEIGHT; ++i){
		rightLine.insert(std::pair<int, bool>(i, false));
	}

	m_HMap.insert(std::pair<int, std::map<int, bool>>(GAME_HEIGHT, bottomLine));

	m_VMap.insert(std::pair<int, std::map<int, bool>>(0, leftLine));
	m_VMap.insert(std::pair<int, std::map<int, bool>>(GAME_WIDTH, rightLine));
	/*m_timer = Timer::GetInstant();
	m_timer->SetGame(this);
	m_timer->SetUpdateFunc(&Game::UpdateGame);*/
}
Game::~Game(){}
Component* Game::CreateComponent(int type){
	int x = rand() % (GAME_WIDTH - 5) + 2;
	Component* com = NULL;
	switch (type){
	case HSHAPE:
		com = new HShape(x, 1);
		break;
	case ISHAPE:
		com = new IVShape(x, 1);
		break;
	case LSHAPE:
		com = new LUpShape(x, 1);
		break;
	case TSHAPE:
		com = new TUpShape(x, 1);
		break;
	case ZSHAPE:
		com = new ZVShape(x, 1);
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
	if (direction == DOWN){
		std::vector<Point*> border = m_currentComponent->GetBottomBorder();
		for (std::vector<Point*>::iterator it = border.begin(); it != border.end(); ++it){
			Point* point = (*it);
			int x = point->GetX();
			int y = point->GetY();
			if (m_HMap.find(y) != m_HMap.end()){
				std::map<int, bool> bottomLine = m_HMap.at(y);
				if (bottomLine.find(x) != bottomLine.end()){
					if (bottomLine.at(x) == false){
						return true;
					}
				}
			}
		}
	}
	else if (direction == RIGHT){
		std::vector<Point*> border = m_currentComponent->GetRightBorder();
		for (std::vector<Point*>::iterator i = border.begin(); i != border.end(); ++i){
			Point* point = (*i);
			int x = point->GetX();
			int y = point->GetY();
			if (m_VMap.find(x) != m_VMap.end()){
				std::map<int, bool> rightLine = m_VMap.at(x);
				if (rightLine.find(y) != rightLine.end()){
					if (rightLine.at(y) == false){
						return true;
					}
				}
			}
		}
	}
	else if (direction == LEFT){
		std::vector<Point*> border = m_currentComponent->GetLeftBorder();
		for (std::vector<Point*>::iterator i = border.begin(); i != border.end(); ++i){
			Point* point = (*i);
			int x = point->GetX();
			int y = point->GetY();
			if (m_VMap.find(x) != m_VMap.end()){
				std::map<int, bool> leftLine = m_VMap.at(x);
				if (leftLine.find(y) != leftLine.end()){
					if (leftLine.at(y) == false){
						return true;
					}
				}
			}
		}
	}

	return false;
}
void Game::UpdataBorder(){
	std::vector<Point*> bottomBorder = m_currentComponent->GetUpBorder();
	for (std::vector<Point*>::iterator it = bottomBorder.begin(); it != bottomBorder.end(); ++it){
		Point* point = (*it);
		int x = point->GetX();
		int y = point->GetY();

		if (m_HMap.find(y) != m_HMap.end()){
			m_HMap.at(y).insert(std::pair<int, bool>(x, false));
		}
		else{
			std::map<int, bool> bottomLine;
			bottomLine.insert(std::pair<int, bool>(x, false));
			m_HMap.insert(std::pair<int, std::map<int, bool>>(y, bottomLine));
		}
	}
	std::vector<Point*> leftBorder = m_currentComponent->GetLeftBorder();
	for (std::vector<Point*>::iterator it = leftBorder.begin(); it != leftBorder.end(); ++it){
		Point* point = (*it);
		int x = point->GetX() + 1;
		int y = point->GetY();
		
		if (m_VMap.find(x) != m_VMap.end()){
			m_VMap.at(x).insert(std::pair<int, bool>(y, false));
		}
		else{
			std::map<int, bool> leftLine;
			leftLine.insert(std::pair<int, bool>(y, false));
			m_VMap.insert(std::pair<int, std::map<int, bool>>(x, leftLine));
		}
	}

	std::vector<Point*> rightBorder = m_currentComponent->GetRightBorder();
	for (std::vector<Point*>::iterator it = rightBorder.begin(); it != rightBorder.end(); ++it){
		Point* point = (*it);
		int x = point->GetX() - 1;
		int y = point->GetY();

		if (m_VMap.find(x) != m_VMap.end()){
			m_VMap.at(x).insert(std::pair<int, bool>(y, false));
		}
		else{
			std::map<int, bool> rightLine;
			rightLine.insert(std::pair<int, bool>(y, false));
			m_VMap.insert(std::pair<int, std::map<int, bool>>(x, rightLine));
		}
	}

}
void Game::Update(){

}
void Game::UpdateGame(){

}