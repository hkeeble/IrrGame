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
        iGUIEnv = nullptr;
        dbgHUD = DebugHUD();
    }

    void Game::Init()
    {
        Log("Initializing IrrGame Object...");

        iDevice = createDevice( video::EDT_OPENGL, dimension2d<u32>(cfg.WindowBounds().width, cfg.WindowBounds().height), 16,
            false, false, false, &keyboard);

        if(iDevice == nullptr)
        {
            Log("Error initializing irrlicht device!");
            SetState(ERR_STATE);
        }

        iDevice->setWindowCaption((wchar_t*)cfg.WindowCaption().c_str());

        // Obtain pointers to useful objects
        iVideoDriver = iDevice->getVideoDriver();
        iGUIEnv = iDevice->getGUIEnvironment();

        // Initialize the input handler
        keyboard = InputHandler();

        // Initialize the game world
        world = World(iDevice->getSceneManager(), iVideoDriver, 10, 10, 10);
        
        // Remove cursor
        iDevice->getCursorControl()->setVisible(false);
        
        dbgHUD = DebugHUD(cfg.WindowBounds().width, cfg.WindowBounds().height, iGUIEnv, IOPath("data/fonts/", FileName("hudFont", "bmp")));
        dbgHUD.AddElement<int>(L"Hello World!", 10, vector2di(50, 50));
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

            if(keyboard.IsKeyDown(KEY_ESCAPE))
                state = EXIT;

            iVideoDriver->beginScene(true, true, SColor(255,100,101,140));

            world.Render();
            iGUIEnv->drawAll();

			dbgHUD.Render();

            iVideoDriver->endScene();
        }

        if(state == ERR_STATE)
            Log("IrrGame exitted with ERR_STATE");
        else
            Log("IrrGame exitted cleanly.");

        FreeIDevice();
    }

	void Game::FreeIDevice()
	{
		iDevice->drop();
		iDevice = nullptr;
	}

    void Game::errFatal(const std::string msg)
    {
        state = ERR_STATE;
    }

    Game::~Game()
    {
 		if(iDevice)
 			FreeIDevice();   
    }
}
