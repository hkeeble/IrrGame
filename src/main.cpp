#include "Game.h"

using namespace IrrGame;

#ifdef NDEBUG
#ifdef WIN32
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif // WIN32
#endif // NDEBUG

int main()
{
    Game game = Game();
    game.Run();
}
