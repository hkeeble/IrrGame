/**
 * @file
 * @author
 * @brief
 */

#include "GameTime.h"

#include <iostream>

namespace IrrGame
{
	GameTime::GameTime()
	{
		deltaTime = 0;
		elapsedTime = 0;
		prevTime = 0;
	}

	GameTime::GameTime(ITimer* timer) : GameTime()
	{
		this->timer = timer;
	}
	
	GameTime::~GameTime()
	{
		
	}

	void GameTime::Update()
	{
		u32 curTime = timer->getTime();
		deltaTime = curTime - prevTime;
		elapsedTime += deltaTime;
		prevTime = curTime;
	}

	u32 GameTime::ElapsedTime() const
	{
		return elapsedTime;
	}

	u32 GameTime::DeltaTime() const
	{
		return deltaTime;
	}
}