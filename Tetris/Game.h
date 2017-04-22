#pragma once
#include "Common.h"
class Timer;
class Component;
class Game{
private:
	Timer* m_timer;
	Component* m_currentComponent;
	Component* m_nextComponent;

	Component* CreateComponent(int type);
	;
	void UpdateGame();
	void DrawBorder();
	
	void Update();
public:
	Game();
	~Game();
	void StartGame();
	void ComponentMove(Direction direction);
};