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
			void Update(const Config& config, const u32& fps, const double& elapsedTime);
		private:
			/* Font IDs */
			u32 smallFont;
			u32 mediumFont;
			u32 largeFont;
			
			/* Element IDs */
			u32 title;
			u32 version;
			u32 fps;
			u32 timer;
	};
}

#endif // DEBUGHUD_H
