#pragma once
#include "Library.h"

class ClCore;
class ClFpsCounter;

class ClCollectObj
{
protected:
	ClCore* core;
	ClFpsCounter* fpsCounter;

	Uint64 ticks = SDL_GetTicks();
	Uint64 spawnStart = SDL_GetTicks();					// Time the spawn Pattern when it's start
	Uint64 spawnEnd = SDL_GetTicks();					// To indicate when the spawn must stop and then give an interval of spawning with the spawnStart

public:
	ClCollectObj();
	~ClCollectObj();

	//============
	// Functions
	//============
	void rectCollObj(SDL_Renderer* rR);
	void initCollObj(SDL_Renderer* rR);
	void spawnRandomizer(const int WINDOW_WIDTH);		// Randomize the coordinates of the spawn  
	void spawner();										// Apply the randomized coordinate and Set the Frequency of the object spawn
	void spawnTimer();									// Manage the cycle and interval of spawn
	void fallGravity();									// Apply the Gravity Once Spawner function has applied coordinates
	void update(SDL_Renderer* rR);						// Render the Objects
	void patternManager();								// To indicate what's pattern is occuring and Define Patterns

	//=============
	// Set&Get
	//=============

	//---------------------------------
	// Surface's Size (Width, Height)
	//---------------------------------
	SDL_Rect srcRed;
	SDL_Rect srcGray;
	SDL_Rect srcGreen;

	//-----------------------
	// Surface's Coordinates
	//-----------------------
	SDL_Rect destRed[5];
	SDL_Rect destGray[5];
	SDL_Rect destGreen[5];

	//-----------------
	// Create Texture
	//-----------------
	SDL_Texture* tRed;
	SDL_Texture* tGray;
	SDL_Texture* tGreen;

	//-----------------
	// Object's State
	//-----------------
	float dropTime;
	bool isDead;

	//----------------
	// Objects spawn
	//----------------
	float redSpX;
	float graySpX;
	float greenSpX;

	float redSpY;
	float graySpY;
	float greenSpY;

	//----------------------
	// Objects coordinates
	//----------------------
	float redX;
	float grayX;
	float greenX;

	float redY;
	float grayY;
	float greenY;

	//-------------------
	// Objects velocity
	//-------------------
	float redVelX;
	float grayVelX;
	float greenVelX;

	float redVelY;
	float grayVelY;
	float greenVelY;

private:
	SDL_Surface* objRedSrfc;
	SDL_Surface* objGraySrfc;
	SDL_Surface* objGreenSrfc;
};

