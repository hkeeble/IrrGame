/**
 * @file    Game.h
 * @author  Henri Keeble
 * @brief   Definitions for a base game class using the Irrlicht rendering engine.
 */

#ifndef IRRGAME_H
#define IRRGAME_H

#include <irrlicht.h>

#include "Config.h"
#include "IrrEventHandler.h"
#include "World.h"
#include "Voxel.h"
#include "IO.h"
#include "DebugHUD.h"

// Irrilicht namespace and subnamespaces
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

/** Primary namespace used by IrrGame */
namespace IrrGame
{
	/** Represents a game state. */
    enum GameState
    {
		READY,		/*!< The game is ready, but Run() has not been called. */
		RUNNING,	/*!< The game is currently running and is updating the main loop. */
		ERR_STATE,	/*!< The game is in error state, and will exit after the current loop. */
		EXIT		/*!< The game is preparing to exit cleanly by user request, and will exit after the current loop. */
    };

	/** A Game class. */
    class Game
    {
        public:
            Game();
            virtual ~Game();

			/** Run the game, entering the main loop. */
            void Run();

        protected:
			Config cfg;					/** The game configuration object. */
			IrrlichtDevice* iDevice;	/** The main Irrlicht device. */
			IVideoDriver* iVideoDriver;	/** The Irrlicht video driver. */
			IGUIEnvironment* iGUIEnv;	/** The Irrlicht GUI Environment. */

			/** Retrieves the current game state. */
            const GameState& GetState() const;
            
			/** Sets the current game state. */
			void SetState(const GameState& state);

			/** Fatal error has occurred, outputs a log message and sets game to error state. */
            void errFatal(const std::string msg);

			/** Frees the Irrlicht device. */
			void FreeIDevice();

			/** Override in base class. */
			virtual void Update();

			/** Override in base class. */
			virtual void Render();

			/** Retrieve the version of IrrGame being used by this game object. */
			std::wstring GetIrrGameVersion() const;

        private:
			/** Initialize Irrlicht. */
			void InitIrrlicht();

			GameState state;				/*!< The current game state. */
			IrrEventHandler eventHandler;	/*!< The game event handler. */
			InputState* inputState;			/*!< The current input state. */
            World world;					/*!< The game world currently loaded. */
            
			bool drawDebugHUD;				/*!< Whether or not the debug HUD is to be rendered. */

			const std::wstring IRRGAME_MAJOR_VER = L"0"; /*!< The current major version of IrrGame being used. */
			const std::wstring IRRGAME_MINOR_VER = L"1"; /*!< The current minor version of IrrGame being used. */

#ifdef _DEBUG
            DebugHUD dbgHUD; /*!< The debugging HUD. */
#endif // _DEBUG
    };
}
#endif // IRRGAME_H
