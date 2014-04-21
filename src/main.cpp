#include "MyGame.h"

using namespace IrrGame;

#ifdef NDEBUG
#ifdef WIN32
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif // WIN32
#endif // NDEBUG

u32 main()
{
	MyGame game = MyGame();
    game.Run();
}
