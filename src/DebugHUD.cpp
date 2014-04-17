/**
 * @file 	DebugHUD.cpp
 * @author	Henri Keeble
 * @brief	Defines a class used to represent a debugging HUD.
 * @see 	DebugHUD
 */
 
 #include "DebugHUD.h"
 
namespace IrrGame
{
#ifdef _DEBUG
	DebugHUD::DebugHUD()
	{
		elements = std::vector<HUDElementBase*>();
	}
	
	DebugHUD::DebugHUD(int windowWidth, int windowHeight, IGUIEnvironment* guiEnv, IOPath fontPath)
	{
		cfgWidth = windowWidth;
		cfgHeight = windowHeight;
		iGUIEnv = guiEnv;
		
		font = iGUIEnv->getFont(fontPath.GetFileAndPath().c_str());
	}
	
	DebugHUD::~DebugHUD()
	{
		for(auto& element : elements)
		{
			delete element;
		}
	}
	
	void DebugHUD::Render()
	{
		for(auto element : elements)
		{
			Log("Rendering HUD...");
			font->draw(element->text.c_str(), rect<s32>((cfgWidth * element->position.X) / 100,
			(cfgHeight * element->position.Y) / 100, 0, 0), video::SColor(255, 255, 255, 255));
		}
	}
#endif // _DEBUG
}
