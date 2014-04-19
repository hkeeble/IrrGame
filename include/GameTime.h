/**
 * @file
 * @author
 * @brief
 */

#ifndef GAMETIME_H
#define GAMETIME_H

#include <time.h>

namespace IrrGame
{
	class GameTime
	{
	public:
		GameTime();
		virtual ~GameTime();

		/** Update the values held by the game time object. */
		void Update();

		/** Retrieve the total elapsed game time. */
		double ElapsedTime() const;

		/** Retrieve delta time since the last call to update. */
		double DeltaTime() const;

	private:
		tm lastElaspedTime;	/*!< Elapsed time on previous update. */
		double deltaTime;	/*!< Delta time since last update. */
		double elapsedTime; /*!< Total elapsed game time.*/
	};
}

#endif // GAMETIME_H