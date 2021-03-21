#pragma once
#include "SDL.h"
#include <iostream>


class timer 
{
public:

	timer(const timer&) = delete;

	static timer& get() 
	{
		static timer instance;
		return instance;
	}

	
	static float getElapsedTimer() { return get().IgetElapsedTime(); }

	static void startTimer() { return get().IstartTimer(); }

	static void stopTimer() { return get().IstopTimer(); }

	static void FPSFrameCap60() { return get().IFPSFrameCap60(); }

	static float getDeltaTime() { return get().IgetDeltaTime(); }

	static void restartTime() { return get().IrestartTime(); }

	static void pauseTime() { return get().IpauseTime(); }

	static void resumeTime() { return get().IresumeTime(); }

	timer()
	{
		TargetDeltaTime = 1.5;
		lastTime = 0;
		start = 0;
		end = 0;
		elapsedTime = 0;
		deltaTime = 0;
		FPS = 60;
		frameDelay = 1000 / FPS;
		timerControl = false;
		currentTime = 0;
	}

	~timer() 
	{
		
	}

	

private:

	float IgetElapsedTime()
	{
		return seconds;
	}


	void IstartTimer()
	{
		
		if (timerControl == false) 
		{
			currentTime += deltaTime;
			if (currentTime >= 40) 
			{
				seconds+=0.25;
				currentTime = 0;
			}
		}
			
	}

	void IstopTimer()
	{
		timerControl = true;
		seconds = 0;
		currentTime = 0;
	}

	void IFPSFrameCap60()
	{
		

		frametime = SDL_GetTicks() - framestart;

		if (frameDelay > frametime)
		{
			SDL_Delay(frameDelay - frametime);
		}
		framestart = SDL_GetTicks();
	}

	float IgetDeltaTime()
	{

		deltaTime = (SDL_GetTicks() - lastTime) * (FPS/1000);

		if (deltaTime > TargetDeltaTime)
			deltaTime = TargetDeltaTime;

		lastTime = SDL_GetTicks();


		return deltaTime;
	}

	void IrestartTime() 
	{
		seconds = 0;
		currentTime = 0;
	}

	void IpauseTime() 
	{
		timerControl = true;
	}

	void IresumeTime() 
	{
		timerControl = false;
	}

	float TargetDeltaTime, lastTime, FPS, frameDelay, deltaTime, framestart, frametime;
	float  start, end, elapsedTime, seconds, currentTime;
	bool timerControl;
	

};

