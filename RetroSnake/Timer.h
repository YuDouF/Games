#pragma once
#include <windows.h>
#include <time.h>
#include "Game.h"
class Timer{
	friend DWORD WINAPI funproc(LPVOID lpparentet);
public:
	typedef void(Game::*Update)();
	static Timer* GetInstant();
	~Timer();
	void SetGame(Game* game);
	void SetUpdateFunc(Update update);
	void SpeedUp();
	void StartTimer();
	void StopTimer();

private:
	Timer();
	static Timer* m_timer;
	Game* m_game;
	Update m_updateFunc;
	int m_speed;
	HANDLE m_hThread;
	bool m_close;
};
