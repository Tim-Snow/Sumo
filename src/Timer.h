#ifndef TIMER
#define TIMER

#include <SDL.h>
#include <iostream>

using namespace std;
class Timer
{
	public:

		Timer();
		~Timer();

		//Timer actions
		void start();
		void stop();
		void pause();
		void resume();

		//Counts the current frames
		int fCounter();
		//Average fps
		int fps();
		//Get the ticks
		/*Uint32*/ int gTicks();
		//Constast amount of frames
		static const int fConstant=20;
		//Check the timer actions
		bool started();
		bool paused();
		bool limit();
	protected:
		int seconds;
		//Current frames
		int cFrames;
		//Average frames per second
		int avgFrames;
		//Initial Ticks
		/*Uint32*/ int sTicks; 
		//Stores how many ticks before the pause
		/*Uint32*/ int pTicks; 
		
		//The current action
		bool tStarted;
		bool tPaused;
};
#endif