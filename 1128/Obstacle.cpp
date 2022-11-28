#include "Library.h"


ClObstacle::ClObstacle()
{

}

ClObstacle::~ClObstacle()
{

}

void ClObstacle::initObstacle(SDL_Renderer* rR)
{
	SDL_RenderClear(rR);
}

void ClObstacle::DrawObstacle(SDL_Renderer* rR)
{
	//-----------------------------------
	// Coordinates and Size Parameters
	//-----------------------------------
	rect = { x_Obst,
		y_Obst,100,134 };

	SDL_SetRenderDrawColor(rR, 255, 255, 255, 255);
	SDL_RenderDrawRect(rR, &rect);

	SDL_SetRenderDrawColor(rR, 0, 0, 0, 255);
}