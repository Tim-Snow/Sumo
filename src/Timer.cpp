#include "Timer.h"

Timer::Timer()
{
	sTicks = 0;
	pTicks = 0;

	tStarted = false;
	tPaused = false;
}
Timer::~Timer() {	}

void Timer::start()
{
	sTicks = SDL_GetTicks();
	pTicks = 0;

	tStarted = true;
	tPaused = false;
}
void Timer::stop()
{
	sTicks = 0;
	pTicks = 0;

	tStarted = false;
	tPaused = false;
}
void Timer::pause()
{
	if(tStarted && !tPaused)
	{
		tPaused = true;
		pTicks = SDL_GetTicks() - sTicks;
		sTicks = 0;
	}
}
void Timer::resume()
{
	if(tStarted && tPaused)
	{
		tPaused = false;
		sTicks = SDL_GetTicks() - pTicks;
		pTicks = 0;
	}
}
/*int Timer::gTicks()
{
	
}*/
bool Timer::paused()
{
	return tPaused && tStarted;
}
bool Timer::started()
{
	return tStarted;
}
int Timer::fCounter()
{
	return cFrames++;
}
int Timer::fps()
{
	float seconds = 0;
	if(tStarted)
	{
		if(tPaused){
			return pTicks;
		}	else   {
			 return seconds = SDL_GetTicks() - sTicks;
		}
		avgFrames = cFrames/seconds;
	if(avgFrames > 300000)
		return avgFrames = 0;
	}
	return 0;
}