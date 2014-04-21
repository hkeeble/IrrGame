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
				{
					if (inputState->IsKeyUp(event.KeyInput.Key))
						inputState->SetKey(event.KeyInput.Key, KeyState::Pressed);
					else
						inputState->SetKey(event.KeyInput.Key, KeyState::Down);
				}
				else
				{
					if (inputState->IsKeyDown(event.KeyInput.Key) || inputState->IsKeyPressed(event.KeyInput.Key))
						inputState->SetKey(event.KeyInput.Key, KeyState::Released);
					else
						inputState->SetKey(event.KeyInput.Key, KeyState::Up);
				}
			}
			else
				Log("Error! Could not handle key press, no input state registered with event handler.");
		}

		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		{
			if (inputState)
			{
				switch (event.MouseInput.Event)
				{
				case EMIE_LMOUSE_PRESSED_DOWN:
					if (inputState->IsMouseButtonUp(MouseButton::Left) || inputState->IsMouseButtonReleased(MouseButton::Left))
						inputState->SetMouseButton(MouseButton::Left, MouseButtonState::Pressed);
					else
						inputState->SetMouseButton(MouseButton::Left, MouseButtonState::Down);
					break;
				case EMIE_LMOUSE_LEFT_UP:
					inputState->SetMouseButton(MouseButton::Left, MouseButtonState::Up);
					break;
				case EMIE_RMOUSE_PRESSED_DOWN:
					if (inputState->IsMouseButtonUp(MouseButton::Right) || inputState->IsMouseButtonReleased(MouseButton::Right))
						inputState->SetMouseButton(MouseButton::Right, MouseButtonState::Pressed);
					else
						inputState->SetMouseButton(MouseButton::Right, MouseButtonState::Down);
					break;
				case EMIE_RMOUSE_LEFT_UP:
					inputState->SetMouseButton(MouseButton::Right, MouseButtonState::Up);
					break;
				case EMIE_MOUSE_MOVED:
					inputState->SetMousePosition(vector2di(event.MouseInput.X, event.MouseInput.Y));
					break;
				case EMIE_MOUSE_WHEEL:
					inputState->SetMouseWheel(event.MouseInput.Wheel);
					break;
				}
			}
			else
				Log("Error! Could not handle mouse input, no input state registered with event handler.");
		}

		return false;
	}

	KeyboardState::KeyboardState()
	{
		for (u32 i = 0; i < KEY_KEY_CODES_COUNT; i++)
			keyStates[i] = KeyState::Up;

		pressedKeys = std::vector<EKEY_CODE>();
		releasedKeys = std::vector<EKEY_CODE>();
	}

	KeyboardState::~KeyboardState()
	{

	}

	MouseState::MouseState()
	{
		position = vector2di(0, 0);
		leftButton = MouseButtonState::Up;
		rightButton = MouseButtonState::Up;
		wheelDir = 0;
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

		// Update vectors accordingly, more efficient than looping through all keys during flush
		if (state == KeyState::Pressed)
			keyboardState.pressedKeys.push_back(key);
		else if (state == KeyState::Released)
			keyboardState.releasedKeys.push_back(key);
	}

	void InputState::SetMouseButton(MouseButton button, MouseButtonState state)
	{
		if (button == MouseButton::Left)
			mouseState.leftButton = state;
		else if (button == MouseButton::Right)
			mouseState.rightButton = state;
	}

	void InputState::SetMousePosition(vector2di position)
	{
		mouseState.position = position;
	}

	void InputState::SetMouseWheel(const f32& dir)
	{
		mouseState.wheelDir = dir;
	}

	void InputState::Flush()
	{
		for (auto i : keyboardState.pressedKeys) // Set all keys pressed on this frame to down
			SetKey(i, KeyState::Down);
		
		for (auto i : keyboardState.releasedKeys) // Set all keys released on this frame to up
			SetKey(i, KeyState::Up);

		// Reset mouse wheel
		SetMouseWheel(0);

		// Update mouse button states
		if (mouseState.leftButton == MouseButtonState::Pressed)
			SetMouseButton(MouseButton::Left, MouseButtonState::Down);
		if (mouseState.rightButton == MouseButtonState::Released)
			SetMouseButton(MouseButton::Right, MouseButtonState::Up);

		// Clear vectors
		keyboardState.releasedKeys.clear();
		keyboardState.pressedKeys.clear();
	}

	bool InputState::IsKeyDown(EKEY_CODE keyCode) const
	{
		return (keyboardState.keyStates[keyCode] == KeyState::Down);
	}

	bool InputState::IsKeyUp(EKEY_CODE keyCode) const
	{
		return (keyboardState.keyStates[keyCode] == KeyState::Up);
	}

	bool InputState::IsKeyPressed(EKEY_CODE keyCode) const
	{
		return (keyboardState.keyStates[keyCode] == KeyState::Pressed);
	}

	bool InputState::IsKeyReleased(EKEY_CODE keyCode) const
	{
		return (keyboardState.keyStates[keyCode] == KeyState::Released);
	}

	bool InputState::IsMouseButtonDown(MouseButton button) const
	{
		switch (button)
		{
		case MouseButton::Left:
			return (mouseState.leftButton == MouseButtonState::Down);
			break;
		case MouseButton::Right:
			return (mouseState.rightButton == MouseButtonState::Down);
			break;
		default:
			Log("Error! Checking state of unrecognized mouse button!");
			break;
		}
	}

	bool InputState::IsMouseButtonUp(MouseButton button) const
	{
		switch (button)
		{
		case MouseButton::Left:
			return (mouseState.leftButton == MouseButtonState::Up);
			break;
		case MouseButton::Right:
			return (mouseState.rightButton == MouseButtonState::Up);
			break;
		default:
			Log("Error! Checking state of unrecognized mouse button!");
			break;
		}
	}

	bool InputState::IsMouseButtonReleased(MouseButton button) const
	{
		switch (button)
		{
		case MouseButton::Left:
			return (mouseState.leftButton == MouseButtonState::Released);
			break;
		case MouseButton::Right:
			return (mouseState.rightButton == MouseButtonState::Released);
			break;
		default:
			Log("Error! Checking state of unrecognized mouse button!");
			break;
		}
	}

	bool InputState::IsMouseButtonPressed(MouseButton button) const
	{
		switch (button)
		{
		case MouseButton::Left:
			return (mouseState.leftButton == MouseButtonState::Pressed);
			break;
		case MouseButton::Right:
			return (mouseState.rightButton == MouseButtonState::Pressed);
			break;
		default:
			Log("Error! Checking state of unrecognized mouse button!");
			break;
		}
	}

	f32 InputState::MouseWheel() const
	{
		return mouseState.wheelDir;
	}
}