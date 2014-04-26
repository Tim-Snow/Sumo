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
int Timer::gTicks()
{
	if(tStarted)
	{
		if(tPaused){
			cout<<pTicks<<endl;
			return pTicks;
		}	else   {
			cout<<sTicks<<endl;
			return seconds = SDL_GetTicks() - sTicks;
		}
	}
	return 0;
}
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
bool Timer::limit()
{
	return true;
}
int Timer::fps()
{
	avgFrames = 1/seconds;
	if(avgFrames > 60 )
	{
		cout<<avgFrames<<endl;
		return avgFrames = 0;
	} else {
	    return avgFrames = 60;
	}
}