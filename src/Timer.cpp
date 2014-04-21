/**
 * @file
 * @author
 * @brief
 */

#include "Timer.h"

namespace IrrGame
{
	Timer::Timer()
	{
		gameTime = nullptr;
		isRunning = false;
	}
	
	Timer::Timer(GameTime* gameTime)
	{
		this->gameTime = gameTime;
	}

	Timer::~Timer()
	{

	}

	void Timer::Start()
	{
		isRunning = true;
		startTime = gameTime->ElapsedTime();
	}

	void Timer::Stop()
	{
		startTime = 0;
		isRunning = false;
	}

	bool Timer::IsRunning() const
	{
		return isRunning;
	}

	u32 Timer::GetTime() const
	{
		if (isRunning)
			return gameTime->ElapsedTime() - startTime;
		else
			return 0;
	}
}