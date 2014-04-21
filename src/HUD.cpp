/**
 * @file 	HUD.cpp
 * @author	Henri Keeble
 * @brief	Defines a class used to represent a HUD.
 * @see 	HUD
 */
 
 #include "HUD.h"
 
namespace IrrGame
{
	HUD::HUDElement::HUDElement(std::wstring text, std::wstring data, vector2di position, IGUIFont* font, SColor color)
	{
		this->text = text;
		this->data = data;
		this->position = position;
		this->color = color;
		this->font = font;
	}
	
	HUD::HUD()
	{
		elements = std::vector<HUDElement>();
	}
	
	HUD::HUD(const Config& cfg, IGUIEnvironment* guiEnv)
	{
		cfgWidth = cfg.WindowBounds().width;
		cfgHeight = cfg.WindowBounds().height;
		iGUIEnv = guiEnv;
	}
	
	u32 HUD::AddFont(std::string path)
	{
		fonts.push_back(iGUIEnv->getFont(path.c_str()));
		return fonts.size() - 1;	
	}
		
	IGUIFont* HUD::GetFont(u32 id) const
	{
		return fonts.at(id);
	}
		
	void HUD::UpdateElement(u32 elementID, std::wstring newData)
	{
		elements.at(elementID).data = newData;
	}
	
	HUD::~HUD()
	{
	
	}
	
	void HUD::Render()
	{
		for(auto element : elements)
		{
			element.font->draw((element.text + element.data).c_str(), rect<s32>((cfgWidth * element.position.X) / 100,
				(cfgHeight * element.position.Y) / 100, 0, 0), video::SColor(255, 255, 255, 255));
		}
	}
	
	u32 HUD::AddElement(std::wstring text, std::wstring data, vector2di position, u32 font, SColor color)
	{
		if(font < 0 && font > fonts.size())
			Log("Invalid font ID passed into HUD.");
	
		elements.push_back(HUDElement(text, data, vector2di(clamp<u32>(position.X, 0, 100), clamp<u32>(position.Y, 0, 100)), GetFont(font), color));
		return elements.size()-1;
	}
	
	u32 HUD::AddElement(std::wstring text, vector2di position, u32 font, SColor color)
	{
		return AddElement(text, L"", position, font, color); // Add element with blank data
	}
}
