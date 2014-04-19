/**
 * @file IrrEventHandler.cpp
 * @author Henri Keeble
 * @brief Definitions for keyboard input event handlers.
 */

#include "IrrEventHandler.h"
#include "IO.h"

namespace IrrGame
{
	IrrEventHandler::IrrEventHandler()
	{
		inputState = nullptr;
	}

	IrrEventHandler::~IrrEventHandler()
	{
		if (inputState)
			delete inputState;
	}

	void IrrEventHandler::RegisterInputState(InputState* inputState)
	{
		this->inputState = inputState;
	}

	bool IrrEventHandler::OnEvent(const SEvent& event)
	{
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		{
			if (inputState)
			{
				if (event.KeyInput.PressedDown)
					inputState->SetKey(event.KeyInput.Key, KeyState::Down);
				else
					inputState->SetKey(event.KeyInput.Key, KeyState::Up);
			}
			else
				Log("Error! Could not handle key press, no input state registered with event handler.");
		}

		return false;
	}

	KeyboardState::KeyboardState()
	{
		for (int i = 0; i < KEY_KEY_CODES_COUNT; i++)
			keyStates[i] = KeyState::Up;
	}

	KeyboardState::~KeyboardState()
	{

	}

	MouseState::MouseState()
	{
		// Construct Mouse State Here
	}
	
	MouseState::~MouseState()
	{

	}

	InputState::InputState()
	{
		keyboardState = KeyboardState();
		mouseState = MouseState();
	}

	InputState::~InputState()
	{

	}

	void InputState::SetKey(EKEY_CODE key, KeyState state)
	{
		keyboardState.keyStates[key] = state;
	}

	bool InputState::IsKeyDown(EKEY_CODE keyCode) const
	{
		return (keyboardState.keyStates[keyCode] == KeyState::Down);
	}

	bool InputState::IsKeyUp(EKEY_CODE keyCode) const
	{
		return (keyboardState.keyStates[keyCode] == KeyState::Up);
	}
}