/**
 * @file Game.cpp
 * @author Henri Keeble
 * @brief A base game class using the Irrlicht rendering engine.
 */

#include "Game.h"

namespace IrrGame
{
    Game::Game()
    {
        state = READY;
        iDevice = nullptr;
        iVideoDriver = nullptr;
        iSceneManager = nullptr;
        iGUIEnv = nullptr;
    }

    void Game::Init()
    {
        Log("Initializing IrrGame Object...");

        iDevice = createDevice( video::EDT_OPENGL, dimension2d<u32>(cfg.WindowBounds().width, cfg.WindowBounds().height), 16,
            false, false, false, 0);

        if(iDevice == nullptr)
        {
            Log("Error initializing irrlicht device!");
            SetState(ERR_STATE);
        }

        iDevice->setWindowCaption((wchar_t*)cfg.WindowCaption().c_str());

        iVideoDriver = iDevice->getVideoDriver();
        iSceneManager = iDevice->getSceneManager();
        iGUIEnv = iDevice->getGUIEnvironment();
    }

    const GameState& Game::GetState() const
    {
        return state;
    }

    void Game::SetState(const GameState& state)
    {
        this->state = state;
    }

    void Game::Run()
    {
        Init();

        state = RUNNING;

        Log("Entering main game loop...");
        while(state == RUNNING)
        {
            if(!iDevice->run())
                state = EXIT;

            iVideoDriver->beginScene(true, true, SColor(255,100,101,140));

            iSceneManager->drawAll();
            iGUIEnv->drawAll();

            iVideoDriver->endScene();
        }

        if(state == ERR_STATE)
            Log("IrrGame exitted with ERR_STATE");
        else
            Log("IrrGame exitted cleanly.");

        iDevice->drop();
    }

    void Game::errFatal(const std::string msg)
    {
        state = ERR_STATE;
    }

    Game::~Game()
    {
        if(iDevice)
            delete iDevice;
        if(iVideoDriver)
            delete iVideoDriver;
        if(iSceneManager)
            delete iSceneManager;
        if(iGUIEnv)
            delete iGUIEnv;
    }
}
