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
		smallFont	= AddFont("data/fonts/smallFont.xml");
		mediumFont	= AddFont("data/fonts/mediumFont.xml");
		largeFont	= AddFont("data/fonts/largeFont.xml");
		
		title	= AddElement(L"IrrGame Debug Display",			vector2di(2, 0), mediumFont, SColor(255, 255, 255, 255));
		fps		= AddElement(L"FPS: ",							vector2di(2, 95), smallFont, SColor(255, 255, 255, 255));
		timer	= AddElement(L"Time(ms):",				L"0",	vector2di(75, 0), smallFont, SColor(255, 255, 255, 255));
	}

	void DebugHUD::Update(const Config& config, const u32& fps, const double& elapsedTime)
	{
		std::string eTime = std::to_string(elapsedTime);
		std::wstring eTimews;
		eTimews.assign(eTime.begin(), eTime.end());
		eTimews.append(L"s");
		UpdateElement(timer, eTimews);
	}
}
