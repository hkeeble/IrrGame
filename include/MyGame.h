/**
 * @file
 * @author
 * @brief
 */

#ifndef MYGAME_H
#define MYGAME_H

#include "Game.h"

using namespace IrrGame;

class MyGame : public Game
{
public:
	MyGame();
	virtual ~MyGame();
protected:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
};

#endif // MYGAME_H