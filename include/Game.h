/**
 * @file    Game.h
 * @author  Henri Keeble
 * @brief   Definitions for a base game class using the Irrlicht rendering engine.
 */

#ifndef IRRGAME_H
#define IRRGAME_H

#include <irrlicht.h>

#include "Config.h"
#include "InputHandler.h"
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

#define IRRGAME_MAJOR_VER 0
#define IRRGAME_MINOR_VER 1

namespace IrrGame
{
    enum GameState
    {
        READY,
        RUNNING,
        ERR_STATE,
        EXIT
    };

    class Game
    {
        public:
            Game();
            virtual ~Game();
            void Run();
        protected:
            Config cfg;
            IrrlichtDevice* iDevice;
            IVideoDriver* iVideoDriver;
            IGUIEnvironment* iGUIEnv;

            const GameState& GetState() const;
            void SetState(const GameState& state);

            void errFatal(const std::string msg);

			void FreeIDevice();

        private:
            void Init();
            GameState state;
            InputHandler keyboard;
            World world; /*!< The game world currently loaded. */
            bool drawDebugHUD;
            
            void HandleDebugHUD();
            
        #ifdef _DEBUG
            DebugHUD dbgHUD; /*!< The debugging HUD. */
        #endif // _DEBUG
    };
}
#endif // IRRGAME_H
