#include "Library.h"

//====================
// KEY INSTRUCTIONS
//====================

#define KEY_UP		SDL_SCANCODE_UP
#define KEY_DOWN	SDL_SCANCODE_DOWN
#define KEY_LEFT	SDL_SCANCODE_LEFT
#define KEY_RIGHT	SDL_SCANCODE_RIGHT

#define SPEED 200

ClPlayer::ClPlayer()
{

}

void ClPlayer::initPlayerSurface(SDL_Renderer* rR)
{
	tSurface = IMG_Load("GAME_leandre_sprite.png");									// Load the Sprite's Image File
	tIMG = SDL_CreateTextureFromSurface(rR, tSurface);								// Creation of the Surface to apply the loaded Image File
	destinationRectangle.x = 300;
}


ClPlayer::ClPlayer(int x, int y)
{
}

ClPlayer::~ClPlayer()
{
	SDL_FreeSurface(tSurface);														// Destruction of the Surface

}


///============================
/// Input entry to the player
///============================
void ClPlayer::update()
{
	ClInput input;

	if (input.is_key_down(KEY_RIGHT))												// Let move the player if there no collision
	{
		velX = 9.2f;
		flipType = SDL_FLIP_NONE;													// Flipping the Sprite is OFF
		printf(" Right Key Is Pressed\n");
	}
	else
	if (input.is_key_down(KEY_LEFT))
	{
		velX = -9.2f;
		flipType = SDL_FLIP_HORIZONTAL;												// Flipping the Sprite is ON
		printf(" Left Key Is Pressed\n");
	}
	else
	{
		velX = 0;
	}
	printf("%d\n", velX);
}

void ClPlayer::rectPlayerIMG(SDL_Renderer* rR)
{
	ClFpsCounter fpscounter;
	SDL_Surface* optimizedSurface = NULL;

	//optimizedSurface = SDL_ConvertSurface(tSurface, getScreenSurface->format, 0);
	SDL_QueryTexture(tIMG, NULL, NULL, &sourceRectangle.w, &sourceRectangle.h);

	update();

	/*destinationRectangle = {velX + x + offset.x,									// {PositionX, PositionY, Width,Height} Config. to the Sprite
		400 + offset.y,100,134};*/
	destinationRectangle.x +=velX;
	destinationRectangle.y = 400;
	destinationRectangle.w = 100;
	destinationRectangle.h = 134;

	printf("\n%d\n", destinationRectangle.x);
	SDL_RenderCopyEx(rR, tIMG, &sourceRectangle, &destinationRectangle,NULL,NULL,flipType);		// Render Copy the Surface and the Image
	
}

ClInput* ClPlayer::get_input()
{
	return input;
}

ClCollider* ClPlayer::get_collider()
{
	return collider;
}

SDL_Rect ClPlayer::get_coordinates()
{
	return destinationRectangle;
}
