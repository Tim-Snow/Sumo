#ifndef TIMER
#define TIMER

#include <SDL.h>

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

		//Check the timer actions
		bool started();
		bool paused();

	protected:
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