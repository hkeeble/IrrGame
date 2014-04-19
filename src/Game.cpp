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
		InitIrrlicht();
		state = READY;
    }

	void Game::InitIrrlicht()
    {
        Log("Initializing IrrGame Object...");

		// Initialize the input handler
		eventHandler = IrrEventHandler();

		// Create and register an input state.
		inputState = new InputState();
		eventHandler.RegisterInputState(inputState);

		// Create an Irrlicht device, with window bounds, and pass a reference to the event handler.
        iDevice = createDevice( video::EDT_OPENGL, dimension2d<u32>(cfg.WindowBounds().width, cfg.WindowBounds().height), 16,
			false, false, false, &eventHandler);

		// Handle any errors creating the Irrlicht device.
        if(iDevice == nullptr)
        {
            Log("Error initializing irrlicht device!");
            SetState(ERR_STATE);
        }

		// Set the window caption using the current configuration.
		std::wstring caption = L"IrrGame " + GetIrrGameVersion() + L"   :   " + cfg.WindowCaption();
		iDevice->setWindowCaption((wchar_t*)caption.c_str());

        // Obtain pointers to useful objects
        iVideoDriver = iDevice->getVideoDriver();
        iGUIEnv = iDevice->getGUIEnvironment();

        // Initialize the game world
        world = World(iDevice->getSceneManager(), iVideoDriver, 10, 10, 10);
        
        // Remove cursor
        iDevice->getCursorControl()->setVisible(false);
        
		// Initlialize the debug HUD.
        dbgHUD = DebugHUD(cfg, iGUIEnv);
        dbgHUD.Init();
    }

	void Game::SetFPS(const int& fps)
	{
		targetFPS = fps;
	}

	std::wstring Game::GetIrrGameVersion() const
	{
		return L"v" + IRRGAME_MAJOR_VER + L"." + IRRGAME_MINOR_VER;
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
        state = RUNNING;

        Log("Entering main game loop...");
        while(state == RUNNING)
        {
			if (!iDevice->run())
				errFatal("Irrlicht device failed unexpectedly.");

			Update(); // Update the game logic
			
			Render(); // Render the game world
        }

        if(state == ERR_STATE)
            Log("IrrGame exitted with ERR_STATE");
        else
            Log("IrrGame exitted cleanly.");

        FreeIDevice();
    }

	void Game::Update()
	{
		if (inputState->IsKeyDown(KEY_ESCAPE))
			state = EXIT;

#ifdef _DEBUG
		if (inputState->IsKeyDown(KEY_TAB))
			drawDebugHUD = !drawDebugHUD;
#endif // _DEBUG
	}

	void Game::Render()
	{
		iVideoDriver->beginScene(true, true, SColor(255, 100, 101, 140));

		world.Render();
		iGUIEnv->drawAll();
		
#ifdef _DEBUG
		if (drawDebugHUD)
		{
			dbgHUD.Update(cfg, 0);
			dbgHUD.Render();
		}
#endif // _DEBUG

		iVideoDriver->endScene();
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
