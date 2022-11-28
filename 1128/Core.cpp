#include "Library.h"


bool ClCore::quitGame = false;

ClCore::ClCore()
{
	this->quitGame = false;

	//================
	// CREATE WINDOW
	//================
	window = SDL_CreateWindow("Lou-Angel's Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		quitGame = true;
	}

	rR = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//getScreenSurface = SDL_GetWindowSurface(window);
	mainEvent = new SDL_Event();
}

ClCore::~ClCore(void)
{
	SDL_DestroyRenderer(rR);
	SDL_DestroyWindow(window);
}

void ClCore::mainLoop()
{
	//=========
	// CLASSES
	//=========
	ClFpsCounter fpsCounter;
	ClInput input;
	ClPlayer player;
	ClCollider collider;
	ClObstacle obstacle;
	ClHitbox hitbox;
	ClCollectObj collObj;

	//=================
	// INITIALIZATION
	//=================
	player.initPlayerSurface(rR);
	obstacle.initObstacle(rR);
	collObj.ClCollectObj::ClCollectObj();

	//======
	// LOOP
	//=======
	while (!quitGame && mainEvent->type != SDL_QUIT)
	{
		fpsCounter.CapFrameRate();								// Game's Speed is fixed
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(rR);

		player.rectPlayerIMG(rR);								// Render of the Player's Sprite
		collider.collideScreen(player.velX, WINDOW_WIDTH, player.destinationRectangle, hitbox.playerHB, obstacle.rect);
		obstacle.DrawObstacle(rR);
		hitbox.HitboxUpdate(player.destinationRectangle);
		collObj.spawnRandomizer(WINDOW_WIDTH);
		collObj.update(rR);

		SDL_RenderPresent(rR);
		SDL_UpdateWindowSurface(window);
	}
}

int ClCore::get_windowWidth()
{
	return WINDOW_WIDTH;
}
