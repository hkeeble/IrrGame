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
using namespace core;

namespace IrrGame
{
	/** Represents the state of a key. */
	enum class KeyState
	{
		Pressed,	/*! Key has just been pressed.*/
		Released,	/*! Key has just been released.*/
		Up,			/*!< Key is up. */
		Down		/*!< Key is down. */
	};

	/** Typedef of keystate used to represent the state of a mouse button. */
	typedef KeyState MouseButtonState;

	enum class MouseButton
	{
		Left,
		Right
	};

	/** Represents the current state of the keyboard. */
	class KeyboardState
	{
	public:
		friend class InputState;
	private:
		KeyboardState();
		virtual ~KeyboardState();
		KeyState keyStates[KEY_KEY_CODES_COUNT]; /** Collection of the state of each key. */

		std::vector<EKEY_CODE> pressedKeys; /*!< Keeps track of keys pressed this frame. */
		std::vector<EKEY_CODE> releasedKeys; /*!< Keeps track of keys released this frame. */
	};

	/** Represents the current state of the mouse. */
	class MouseState
	{
	public:
		friend class InputState;
	private:
		MouseState();
		virtual ~MouseState();

		vector2di position;				/*!< Position of the mouse in the window. */
		f32	wheelDir;					/*!< Direction and speed the mouse wheel has moved. */
		MouseButtonState leftButton;	/*!< State of the left mouse button. */
		MouseButtonState rightButton;	/*!< State of the right mouse button. */
	};

	/** Stores the current input state. */
	class InputState
	{
	public:
		InputState();
		virtual ~InputState();

		/** Is the given key currently down? */
		bool IsKeyDown(EKEY_CODE keyCode) const;
		
		/** Is the given key currently up? */
		bool IsKeyUp(EKEY_CODE keyCode) const;

		/** Has the given key just been pressed? */
		bool IsKeyPressed(EKEY_CODE keyCode) const;

		/** Has the given key just been released? */
		bool IsKeyReleased(EKEY_CODE keyCode) const;

		/** Is the given mouse button currently down? */
		bool IsMouseButtonDown(MouseButton button) const;
		
		/** Is the given mouse button currently up? */
		bool IsMouseButtonUp(MouseButton button) const;

		/** Has the given mouse button just been released? */
		bool IsMouseButtonReleased(MouseButton button) const;
		
		/** Has the given mouse button just been pressed? */
		bool IsMouseButtonPressed(MouseButton button) const;

		/** Get the value of the mouse wheel. */
		f32 MouseWheel() const;

		/** Flushes the input state. Any pressed buttons are set to down. Placed at the end of a call to update. */
		void Flush();

		friend class IrrEventHandler;

	private:
		/** Sets the state of the given key. */
		void SetKey(EKEY_CODE key, KeyState state);

		/** Sets the state of the given mouse button. */
		void SetMouseButton(MouseButton button, MouseButtonState state);

		/** @overload */
		void SetMousePosition(vector2di position);

		/** Set the current state of the mouse wheel. */
		void SetMouseWheel(const f32& dir);

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
