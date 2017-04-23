#include "Game.h"
#include "Timer.h"
#include "Common.h"
#include <ctime>
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
	SHAPETYPE type = SHAPETYPE(rand() % 5);
	m_currentComponent = CreateComponent(type);
	type = SHAPETYPE(rand() % 5);
	m_nextComponent = CreateComponent(type);
	
	for (int y = 0; y < GAME_HEIGHT; ++y){
		for (int x = 0; x < GAME_WIDTH; ++x){
			if (y == 0 || y == GAME_HEIGHT - 1 || x == 0 || x == GAME_WIDTH - 1){
				m_Map[y][x] = false;
			}
			else{
				m_Map[y][x] = true;
			}
		}
	}
	/*std::map<int, bool> bottomLine;
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
	m_VMap.insert(std::pair<int, std::map<int, bool>>(GAME_WIDTH, rightLine));*/
	/*m_timer = Timer::GetInstant();
	m_timer->SetGame(this);
	m_timer->SetUpdateFunc(&Game::UpdateGame);*/
}
Game::~Game(){}
Component* Game::CreateComponent(SHAPETYPE type){
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
	for (int y = 0; y < GAME_HEIGHT; ++y){
		for (int x = 0; x < GAME_WIDTH; ++x){
			CursorToPos(x, y);
			if (y == 0 || y == GAME_HEIGHT - 1 || x == 0 || x == GAME_WIDTH - 1){
				std::cout << "*";
			}
			else{
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
		Remove();
		m_currentComponent = m_nextComponent;
		srand(time(0));
		SHAPETYPE type = SHAPETYPE(rand() % 5);
		m_nextComponent = CreateComponent(type);
	}
}
void Game::Remove(){
	std::vector<Point*> border = m_currentComponent->GetLeftBorder();
	for (std::vector<Point*>::iterator it = border.begin(); it != border.end(); ++it){
		Point* point = (*it);
		int y = point->GetY();
		int x;
		for (x = 1; x < GAME_WIDTH - 1; ++x){
			if (m_Map[y][x]){
				break;
			}
		}
		if (x == GAME_WIDTH - 1){
			for (int i = 1; i < GAME_WIDTH - 1; ++i){
				m_Map[y][i] = true;
			}
			bool m_MapCopy[GAME_HEIGHT][GAME_WIDTH];
			for (int m = 0; m < GAME_HEIGHT; ++m){
				for (int n = 0; n < GAME_WIDTH; ++n){
					if (m == 0 || m == GAME_HEIGHT - 1 || n == 0 || n == GAME_WIDTH - 1){
						m_MapCopy[m][n] = false;
					}
					else{
						m_MapCopy[m][n] = true;
					}
				}
			}

			for (int m = GAME_HEIGHT - 2; m > 1; --m){
				for (int n = 1; n < GAME_WIDTH - 1; ++n){
					CursorToPos(n, m);
					int t = m;
					if (t <= y){
						--t;
					}
					m_MapCopy[m][n] = m_Map[t][n];
				}
			}

			for (int m = 1; m < GAME_HEIGHT - 1; ++m){
				for (int n = 1; n < GAME_WIDTH - 1; ++n){
					m_Map[m][n] = m_MapCopy[m][n];
				}
			}
			
			for (int m = 1; m < GAME_HEIGHT - 1; ++m){
				for (int n = 1; n < GAME_WIDTH - 1; ++n){
					CursorToPos(n, m);
					if (m_Map[m][n]){
						std::cout << " ";
					}
					else{
						std::cout << "*";
					}
				}
			}
			/*bool temp[GAME_HEIGHT][GAME_WIDTH];
			for (int y = 0; y < GAME_HEIGHT; ++y){
				for (int x = 0; x < GAME_WIDTH; ++x){
					if (y == 0 || y == GAME_HEIGHT - 1 || x == 0 || x == GAME_WIDTH - 1){
						temp[y][x] = false;
					}
					else{
						temp[y][x] = true;
					}
				}
			}
			for (int y = GAME_HEIGHT - 2; y > 0; --y){
				for (int x = 1; x < GAME_WIDTH - 1; ++x){
					if (y == 0 || y == GAME_HEIGHT - 1 || x == 0 || x == GAME_WIDTH - 1){
						temp[y][x] = false;
					}
					else{
						temp[y][x] = true;
					}
				}
			}*/
		}
		else{
			x = 1;
		}
	}
	/*std::vector<Point*> border = comp->GetLeftBorder();
	for (std::vector<Point*>::iterator it = border.begin(); it != border.end(); ++it){
		Point* point = (*it);
		int x = point->GetX();
		int y = point->GetY();
		int i;
		for (i = 1; i < GAME_WIDTH - 1; ++i){
			if (m_VMap.find(i) != m_VMap.end()){
				if (m_VMap.at(i).at(y)){
					break;
				}
			}
		}
		if (i == GAME_WIDTH - 2){
			for (int x = 1; x < GAME_WIDTH - 1; ++x){
				CursorToPos(x, y);
				std::cout << " ";
			}
			for (i = 1; i < GAME_WIDTH - 1; ++i){
				
			}
		}
		else{
			i = 0;
		}
	}*/
	
}
bool Game::StopComponent(Direction direction){
	std::vector<Point*> border;
	switch (direction){
	case DOWN:
		border = m_currentComponent->GetBottomBorder();
		break;
	case RIGHT:
		border = m_currentComponent->GetRightBorder();
		break;
	case LEFT:
		border = m_currentComponent->GetLeftBorder();
		break;
	}
	for (std::vector<Point*>::iterator it = border.begin(); it != border.end(); ++it){
		Point* point = (*it);
		int x = point->GetX();
		int y = point->GetY();

		if (!m_Map[y][x]){
			return true;
		}
	}
	return false;
	/*if (direction == DOWN){
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
	else{
		std::vector<Point*> border;
		if (direction == RIGHT){
			border = m_currentComponent->GetRightBorder();
		}
		else if (direction == LEFT){
			border = m_currentComponent->GetLeftBorder();
		}
		for (std::vector<Point*>::iterator i = border.begin(); i != border.end(); ++i){
			Point* point = (*i);
			int x = point->GetX();
			int y = point->GetY();
			if (m_VMap.find(x) != m_VMap.end()){
				std::map<int, bool> line = m_VMap.at(x);
				if (line.find(y) != line.end()){
					if (line.at(y) == false){
						return true;
					}
				}
			}
		}
	}
	return false;*/
}
void Game::UpdataBorder(){
	std::vector<Point*> temp = m_currentComponent->GetLocation();
	for (std::vector<Point*>::iterator it = temp.begin(); it != temp.end(); ++it){
		Point* point = (*it);
		int x = point->GetX();
		int y = point->GetY();
		m_Map[y][x] = false;
	}
	/*std::vector<Point*> bottomBorder = m_currentComponent->GetUpBorder();
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
	}*/

}
void Game::Update(){

}
void Game::UpdateGame(){

}