/**
 * @file 	DebugHUD.h
 * @author	Henri Keeble
 * @brief	Declares a class used to represent a debugging HUD.
 * @see DebugHUD
 */
 
#ifndef DEBUGHUD_H
#define DEBUGHUD_H

#include <irrlicht.h>
#include <vector>
#include <string>
 
#include "IO.h"

using namespace irr;
using namespace core;
using namespace gui;
 
namespace IrrGame
{
	struct HUDElementBase
	{
		std::wstring text;
		vector2di position;
	};

	template<class T>
	struct HUDElement : public HUDElementBase
	{
		HUDElement(std::wstring text, T data, vector2di position)
		{
			this->text = text;
			this->data = data;
			this->position = position;
		}
		T data;
	};

#ifdef _DEBUG
	/** Debugging heads up display. */
	class DebugHUD
	{
	public:
		DebugHUD();
		
		/** Construct a new debugging heads up display. */
		/**
		 * @param windowWidth   The width of the window.
		 * @param windowHeight  The height of the window.
		 * @param guiEnv 		The Irrlicht GUI environment used to render text.
		 */
		DebugHUD(int windowWidth, int windowHeight, IGUIEnvironment* guiEnv, IOPath fontPath);
		virtual ~DebugHUD();
	
		/** Add a HUD element that displays some form of data. */
		/**
		 * @param text Text to display next to the data value.
		 * @param data The data value to display.
		 * @param position The position to display the text at (x and y between 1-100).
		 * @return The ID of the element being inserted.
		 */	
		template<class T> int AddElement(std::wstring text, T data, vector2di position);
		
		/** Update an element in the HUD with new data. */
		/**
		 * @param elementID ID of the element.
		 * @param newData	The new data to display for this element.
		 */
		template<class T> void UpdateElement(int elementID, T newData);
		
		/** Draw the HUD elements to the screen. */
		void Render();
		
	private:
		IGUIFont* font; 						/*!< The font used by the HUD. */
		IGUIEnvironment* iGUIEnv;				/*!< The GUI environment from the Irrlicht device used by this HUD. */
		int cfgWidth, cfgHeight;				/*!< The window width and height of the HUD. */
		std::vector<HUDElementBase*> elements;	/*!< The list of elements in the HUD. */
	};
	
	template<class T> int DebugHUD::AddElement(std::wstring text, T data, vector2di position)
	{
		elements.push_back(new HUDElement<T>(text, data,
			vector2di(clamp<int>(position.X, 0, 100), clamp<int>(position.Y, 0, 100)));
		
		return elements.size()-1;
	}
	
	template<class T> void DebugHUD::UpdateElement(int elementID, T newData)
	{
		HUDElement<T>* e = static_cast<HUDElement<T>*>(elements.at(elementID));
		
		static_assert(std::is_same<decltype(newData), decltype(e->data)>::value,
			"Updating Debug HUD element with wrong type! Are you using the correct element ID?");
		
		e->data = newData;
	}
	
#endif // _DEBUG

/* Version for release builds, functions are all empty */
#ifdef NDEBUG
	class DebugHUD
	{
	public:
		DebugHUD() { }
		DebugHUD(int windowWidth, int windowHeight, IGUIEnvironment* guiEnv, IOPath fontPath) { }
		virtual ~DebugHUD() { }
		template<class T> int AddElement(std::wstring text, T data, vector2di position) { }
		template<class T> void UpdateElement(int elemenID, T newData) { }
		void Render() { }
	};
#endif // NDEBUG
}
 
#endif // DEBUGHUD_H
