/**
 * @file    Game.h
 * @author  Henri Keeble
 * @brief   Definitions for a base game class using the Irrlicht rendering engine.
 */

#ifndef IRRGAME_H
#define IRRGAME_H

#include <irrlicht.h>

#include "Config.h"
#include "Log.h"

// Irrilicht namespace and subnamespaces
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

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
            ISceneManager* iSceneManager;
            IGUIEnvironment* iGUIEnv;

            const GameState& GetState() const;
            void SetState(const GameState& state);

            void errFatal(const std::string msg);
        private:
            void Init();
            GameState state;
    };
}
#endif // IRRGAME_H
