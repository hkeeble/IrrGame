/**
 * @file 	HUD.h
 * @author	Henri Keeble
 * @brief	Declares a class used to represent a HUD.
 * @see HUD
 */
 
#ifndef HUD_H
#define HUD_H

#include <irrlicht.h>
#include <vector>
#include <string>
 
#include "IO.h"
#include "Config.h"

using namespace irr;
using namespace core;
using namespace gui;
using namespace video;
 
namespace IrrGame
{
	/** Heads up display. Derive from this and implement the init function for bespoke heads up displays. */
	class HUD
	{
	public:
		HUD();
		
		/** Construct a new heads up display. */
		/**
		 * @param windowWidth   The width of the window.
		 * @param windowHeight  The height of the window.
		 * @param guiEnv 		The Irrlicht GUI environment used to render text.
		 */
		HUD(const Config& cfg, IGUIEnvironment* guiEnv);
		virtual ~HUD();
	
		/** Draw the HUD elements to the screen. */
		void Render();

		/** Interface function, override this in base class. */
		virtual void Init() = 0;

	protected:	
		/** Add a HUD element that displays some form of data. */
		/**
		 * @param text 		Text to display next to the data value.
		 * @param data 		The data value to display.
		 * @param position  The position to display the text at (x and y between 1-100).
		 * @return 			The ID of the element being inserted. Store this for later use in order to update the element.
		 */	
		int AddElement(std::wstring text, std::wstring data, vector2di position, int font, SColor color);
		
		/** Add a HUD element with only text. */
		/**
		 * @param text 		Text to display next to the data value.
		 * @param position  The position to display the text at (x and y between 1-100).
		 * @return 			The ID of the element being inserted. Store this for later use in order to update the element.
		 */	
		int AddElement(std::wstring text, vector2di position, int font, SColor color);
		
		/** Update an element in the HUD with new data. */
		/**
		 * @param elementID ID of the element.
		 * @param newData	The new data to display for this element.
		 */
		void UpdateElement(int elementID, std::wstring newData);
		
		/** Adds a font to the HUD. */
		/**
		 * @param path Path of the font XML file and all image files.
		 * @return 	   Returns the ID of the font.
		 */
		int AddFont(IOPath path);

		/** Returns font contained within the given ID. */
		/**
		 * @param id The ID of the font.
		 */
		IGUIFont* GetFont(int id) const;

	private:
		/** Class that represents a HUD element. */
		struct HUDElement
		{
			/** Construct a new HUD element. */
			/**
			 * @param text 		Text to display in this element.
			 * @param data 		The data to display in this element.
			 * @param position  The position of this element, clamped to 0-100 on both axes.
			 * @param font		The font ID used by this element.
			 * @param color		The color of this HUD element.
			 */
			HUDElement(std::wstring text, std::wstring data, vector2di position, IGUIFont* font, SColor color);
	
			std::wstring text; 	/*!< Text stored by this element. */
			std::wstring data;  /*!< The data stored and displayed by this element. */
			vector2di position; /*!< Position of this element. Clamped to 0-100 X and 0-100 Y. */
			IGUIFont* font;		/*!< Font used by this element. */
			SColor color;		/*!< Color used by this HUD element. */
		};

		std::vector<IGUIFont*> fonts; 		/*!< Small font used by the HUD. */
		
		IGUIEnvironment* iGUIEnv;			/*!< The GUI environment from the Irrlicht device used by this HUD. */
		int cfgWidth;						/*!< The window width of the HUD. */
		int cfgHeight;						/*!< The window width of the HUD. */
		std::vector<HUDElement> elements;	/*!< The list of elements in the HUD. */
	};
}
 
#endif // HUD_H
