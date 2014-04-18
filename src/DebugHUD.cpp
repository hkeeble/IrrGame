/**
 * @file 	DebugHUD.h
 * @author 	Henri Keeble
 * @brief 	Declares a debugging HUD for IrrGame.
 * @see		DebugHUD
 */

#include "DebugHUD.h"

namespace IrrGame
{
	void DebugHUD::Init()
	{
		smallFont = AddFont("data/fonts/smallFont.xml");
		mediumFont = AddFont("data/fonts/mediumFont.xml");
		largeFont = AddFont("data/fonts/largeFont.xml");
		
		title = AddElement(L"IrrGame Debug Display", vector2di(2, 0), mediumFont, SColor(255, 255, 255, 255));
		fps = AddElement(L"FPS: ", vector2di(2, 95), smallFont, SColor(255, 255, 255, 255));
	}

	void DebugHUD::Update(const Config& config, const int& fps)
	{
		
	}
}
