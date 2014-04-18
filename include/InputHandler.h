/**
 * @file InputHandler.cpp
 * @author Henri Keeble
 * @brief Declarations for keyboard input event handlers.
 */

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <irrlicht.h>

using namespace irr;

enum class KeyState
{
	Pressed,	/*!< Key has just been pressed. */
	Released,	/*!< Key has just been released. */
	Down,		/*!< Key is held down. */
	Up			/*!< Key is up. */
};

class InputHandler : public IEventReceiver
{
public:
    InputHandler();
    virtual bool OnEvent(const SEvent& event);
    virtual bool IsKeyDown(EKEY_CODE keyCode) const;

private:
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif // INPUTHANDLER_H
