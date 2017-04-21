#pragma once
#include "common.h"
class Snake;
class TargetSquare;
class Timer;
class Game{
private:
	Timer* m_timer;
	Snake* m_snake;
	TargetSquare* m_target;

	void SetSnake(Snake* snake);
	void CreateTarget();
	void UpdateGame();
	void DrawBorder();
	bool IsOver();
	bool IsEat();
	void Update();
	void UpdateTarget();
public:
	Game(Snake* snake);
	~Game();
	void StartGame();
};