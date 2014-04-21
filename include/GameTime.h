/**
 * @file
 * @author
 * @brief
 */

#ifndef GAMETIME_H
#define GAMETIME_H

#include <ITimer.h>

#ifdef WIN32
	#include <Windows.h>
#endif // WIN32

using namespace irr;

namespace IrrGame
{
	class GameTime
	{
	public:
		GameTime();
		GameTime(ITimer* timer);
		virtual ~GameTime();

		/** Update the values held by the game time object. */
		void Update();

		/** Retrieve the total elapsed game time. */
		u32 ElapsedTime() const;

		/** Retrieve delta time since the last call to update. */
		u32 DeltaTime() const;

	private:
		ITimer* timer;
		u32 prevTime;    /*!< Time on the previous call to update. */
		u32 deltaTime;	 /*!< Delta time in milliseconds since the timer was last updated. */
		u32 elapsedTime; /*!< Total elapsed time in milliseconds. */
	};
}

#endif // GAMETIME_H