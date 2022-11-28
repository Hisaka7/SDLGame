#pragma once

#include "Library.h"

class Input;

class ClCore
{
protected:
	ClCollider* collider;
	ClHitbox* hitbox;

public:
	ClCore();
	~ClCore(void);

	//===========
	// Functions
	//===========
	void mainLoop();
	int get_windowWidth();
	void Draw();

	//========
	// Set
	//========
	SDL_Window* window;
	SDL_Surface* getScreenSurface = NULL;
	const int	WINDOW_WIDTH = 1280;
	int	WINDOW_HEIGHT = 800;
	static bool quitGame;


private:
	
	SDL_Renderer* rR;
	SDL_Event* mainEvent;
};