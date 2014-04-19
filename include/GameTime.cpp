/**
 * @file
 * @author
 * @brief
 */

#include "GameTime.h"

namespace IrrGame
{
	GameTime::GameTime()
	{
		deltaTime = 0;
		elapsedTime = 0;
	}
	
	GameTime::~GameTime()
	{

	}

	void GameTime::Update()
	{
		// Update game time objects here...
	}

	double GameTime::ElapsedTime() const
	{
		return elapsedTime;
	}

	double GameTime::DeltaTime() const
	{
		return deltaTime;
	}
}