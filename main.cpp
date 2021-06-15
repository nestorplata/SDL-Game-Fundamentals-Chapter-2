
#include "Game.h"
#include "Windows.h"

#pragma warning(disable : 4996)

//our Game -object
//nigga


Game* g_game = 0; 

//our Game Object
int main(int argc, char* argv [] ) {
	
	AllocConsole();
	freopen("CON", "w", stdout);

	g_game = new Game();
	g_game->init("chapter 1", 100, 100, 640, 480, SDL_WINDOW_RESIZABLE);

	while (g_game ->running()) 
	{
		g_game-> handleEvents();
		g_game-> update();
		g_game-> render();
	}

	g_game->clean();

	return 0;

}
 
	                                                                                                                  
