/**
 * @file 	DebugHUD.h
 * @author 	Henri Keeble
 * @brief 	Declares a debugging HUD for IrrGame.
 * @see		DebugHUD
 */

#ifndef DEBUGHUD_H
#define DEBUGHUD_H

#include "HUD.h"

namespace IrrGame
{
	class DebugHUD : public HUD
	{
		public:
			DebugHUD() : HUD() { }
			DebugHUD(const Config& cfg, IGUIEnvironment* guiEnv) : HUD(cfg, guiEnv) { }
		
			void Init();
			void Update(const Config& config, const int& fps);
		private:
			/* Font IDs */
			int smallFont;
			int mediumFont;
			int largeFont;
			
			/* Element IDs */
			int title;
			int version;
			int fps;
	};
}

#endif // DEBUGHUD_H
