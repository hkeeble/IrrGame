/**
 * @file
 * @author
 * @brief
 */

#ifndef TIMER_H
#define TIMER_H

#include <irrlicht.h>
#include "GameTime.h"

using namespace irr;

namespace IrrGame
{
	class Timer
	{
	public:
		Timer();
		Timer(GameTime* gameTime);
		virtual ~Timer();

		/** Start the timer. */
		void Start();
		
		/** Stop the timer. */
		void Stop();
		
		/** Returns whether or not the timer is currently running. */
		bool IsRunning() const;

		/** Get the milliseconds stored by the timer. */
		u32 GetTime() const;
	private:
		GameTime* gameTime; /*!< Pointer to game time. */
		u32 startTime;		/*!< Time the timer was started. */
		bool isRunning;		/*!< Whether or not the timer is running. */
	};
}

#endif // TIMER_H