/**
 * @file InputHandler.cpp
 * @author Henri Keeble
 * @brief Definitions for keyboard input event handlers.
 */

#include "InputHandler.h"

InputHandler::InputHandler()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

bool InputHandler::OnEvent(const SEvent& event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    return false;
}

bool InputHandler::IsKeyDown(EKEY_CODE keyCode) const
{
    return KeyIsDown[keyCode];
}
