#pragma once
#include "Common.h"
#include <map>
class Timer;
class Component;
class Point;
class Game{
private:
	Timer* m_timer;
	std::map<int, std::map<int, bool>> m_VMap;
	int m_leftLine[GAME_HEIGHT];
	int m_bottomLine[GAME_WIDTH];
	int m_rightLine[GAME_HEIGHT];
	Component* m_currentComponent;
	Component* m_nextComponent;

	Component* CreateComponent(int type);
	bool StopComponent(Direction direction);
	void UpdataBorder();
	void UpdateGame();
	void DrawBorder();
	
	void Update();
public:
	Game();
	~Game();
	void StartGame();
	void ComponentMove(Direction direction);
};