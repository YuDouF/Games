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
	std::map<int, std::map<int, bool>> m_HMap;
	Component* m_currentComponent;
	Component* m_nextComponent;

	Component* CreateComponent(SHAPETYPE type);
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