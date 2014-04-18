/**
 * @file 	HUD.cpp
 * @author	Henri Keeble
 * @brief	Defines a class used to represent a HUD.
 * @see 	HUD
 */
 
 #include "HUD.h"
 
namespace IrrGame
{
#ifdef _DEBUG
	HUD::HUD()
	{
		elements = std::vector<HUDElementBase*>();
	}
	
	HUD::HUD(int windowWidth, int windowHeight, IGUIEnvironment* guiEnv, IOPath fontPath)
	{
		cfgWidth = windowWidth;
		cfgHeight = windowHeight;
		iGUIEnv = guiEnv;
		
		font = iGUIEnv->getFont(fontPath.GetFileAndPath().c_str());
	}
	
	HUD::~HUD()
	{
		for(auto& element : elements)
		{
			delete element;
		}
	}
	
	void HUD::Render()
	{
		for(auto element : elements)
		{
			font->draw(element->text.c_str(), rect<s32>((cfgWidth * element->position.X) / 100,
			(cfgHeight * element->position.Y) / 100, 0, 0), video::SColor(255, 255, 255, 255));
		}
	}
#endif // _DEBUG
}
