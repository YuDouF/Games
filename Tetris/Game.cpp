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
	m_timer = Timer::GetInstant();
	m_timer->SetGame(this);
	m_timer->SetUpdateFunc(&Game::UpdateGame);
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
	m_timer->StartTimer();
}
void Game::ComponentMove(Direction direction){
	if (!StopComponent(direction)){
		m_currentComponent->Clean();
		if (direction == UP && StopComponent(RIGHT)){
			if (!StopComponent(LEFT)){
				m_currentComponent->SetParentX(m_currentComponent->GetParentX() - 1);
			}
			else{
				direction = DOWN;
			}
		}

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
		}
		else{
			x = 1;
		}
	}
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
}
void Game::UpdataBorder(){
	std::vector<Point*> temp = m_currentComponent->GetLocation();
	for (std::vector<Point*>::iterator it = temp.begin(); it != temp.end(); ++it){
		Point* point = (*it);
		int x = point->GetX();
		int y = point->GetY();
		m_Map[y][x] = false;
	}
}
void Game::Update(){

}
void Game::UpdateGame(){
	ComponentMove(Direction(DOWN));
}