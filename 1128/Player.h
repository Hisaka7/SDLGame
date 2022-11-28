#pragma once

#include "Library.h"

class ClInput;
class ClCollider;
class ClFpsCounter;

class ClPlayer
{
protected:

	ClInput* input;
	ClCollider* collider;
	ClObstacle* obstacle;
	ClHitbox* hitbox;
	ClFpsCounter* fpscounter;
	
public:
	ClPlayer();
	ClPlayer(int x, int y);
	~ClPlayer();

	//============
	// Functions
	//============
	void rectPlayerIMG(SDL_Renderer* rR);			// Render the Player's Sprite
	void initPlayerSurface(SDL_Renderer* rR);
	void update();
	void setIMG(SDL_Renderer* rR);

	//===========
	// Set&Get
	//===========
	ClInput* get_input();							// Get the Input instuctions
	ClCollider* get_collider();						// Get the Collider instructions
	SDL_Rect get_coordinates();						// ??????????????????????

	//------------------
	// Image Parameters
	//-------------------
	SDL_Rect sourceRectangle;						// Image Size(Width, Height)
	SDL_Rect destinationRectangle;					// Image Coordinates
	SDL_Surface* getScreenSurface = NULL;			// Create Surface
	SDL_Texture* tIMG;								// Load Image Data

	int x;
	int y;
	float velX;

private:
	SDL_RendererFlip flipType = SDL_FLIP_NONE;
	Offset offset;
	SDL_Rect* rRect;
	SDL_Surface* tSurface;
};