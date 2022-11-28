#pragma once

#include "Library.h"


class ClObstacle
{
public:
	ClObstacle();
	~ClObstacle();

	//============
	// Functions
	//============
	void initObstacle(SDL_Renderer* rR);					// Initialize Obstacle
	void DrawObstacle(SDL_Renderer* rR);					// Render the Obstacle
	
	//------
	// Set
	//------
	SDL_Rect rect;
	int x_Obst = 200;
	int y_Obst = 400;
};

