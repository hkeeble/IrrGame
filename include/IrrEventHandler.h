/**
 * @file IrrEventHandler.cpp
 * @author Henri Keeble
 * @brief Declarations for keyboard input event handlers.
 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <irrlicht.h>
#include <vector>

using namespace irr;

namespace IrrGame
{
	/** Represents the state of a key. */
	enum class KeyState
	{
		Up,		/*!< Key is up. */
		Down	/*!< Key is down. */
	};

	/** Represents the current state of the keyboard. */
	class KeyboardState
	{
	public:
		friend class InputState;
	private:
		KeyboardState();
		virtual ~KeyboardState();
		KeyState keyStates[KEY_KEY_CODES_COUNT];
	};

	/** Represents the current state of the mouse. */
	class MouseState
	{
	public:
		friend class InputState;
	private:
		MouseState();
		virtual ~MouseState();
	};

	/** Stores the current input state. */
	class InputState
	{
	public:
		InputState();
		virtual ~InputState();

		/** Is the given key currently down? */
		virtual bool IsKeyDown(EKEY_CODE keyCode) const;
		
		/** Is the given key currently up? */
		virtual bool IsKeyUp(EKEY_CODE keyCode) const;

		/** Sets the state of the given key. */
		void SetKey(EKEY_CODE key, KeyState state);

	private:
		KeyboardState keyboardState;
		MouseState mouseState;
	};

	/** Implements IEventReceiver, handles keyboard events. */
	class IrrEventHandler : public IEventReceiver
	{
	public:
		IrrEventHandler();
		virtual ~IrrEventHandler();
		virtual bool OnEvent(const SEvent& event);

		/** 
		 * Registers an input state to be updated by the event handler. Once registered, the IrrGameHandler is responsible for managing it as a resource, and
		 * deletion of it.
		 */
		/**
		 * @param inputState The input state to update with the event handler.
		 */
		void RegisterInputState(InputState* inputState);

	private:
		InputState* inputState;
	};
}
#endif // INPUTHANDLER_H
