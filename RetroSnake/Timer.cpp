#include "Timer.h"

DWORD WINAPI funproc(LPVOID lpparentet)
{
	Timer* timer = Timer::GetInstant();
	
	clock_t startTime, endTime;
	startTime = endTime = clock();
	while (!timer->m_close){
		endTime = clock();
		if (endTime - startTime >= timer->m_speed){
			(timer->m_game->*(timer->m_updateFunc))();
			endTime = startTime = clock();
		}
	}
	return 0;
}
Timer* Timer::m_timer = new Timer();
Timer* Timer::GetInstant(){
	if (m_timer == NULL){
		m_timer = new Timer();
	}
	return m_timer;
}
Timer::Timer(){
	m_close = false;
	m_speed = 500;
}
Timer::~Timer(){}
void Timer::SetGame(Game* game){
	m_game = game;
}
void Timer::SetUpdateFunc(Update update){
	m_updateFunc = update;
}
void Timer::SpeedUp(){
	m_speed -= 20;
}
void Timer::StartTimer(){
	m_hThread = CreateThread(NULL, 0, funproc, NULL, 0, NULL);
}
void Timer::StopTimer(){
	m_close = true;
	CloseHandle(m_hThread);
}
