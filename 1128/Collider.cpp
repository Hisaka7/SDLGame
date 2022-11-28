#include "Library.h"

ClCollider::ClCollider()
{

}

ClCollider::~ClCollider()
{

}


void ClCollider::collideScreen(float& velX, const int WINDOW_WIDTH,SDL_Rect &destinationRectangle,SDL_Rect &playerHB, SDL_Rect& rect)
{
	if ((destinationRectangle.x < 0) || (destinationRectangle.x + destinationRectangle.w > WINDOW_WIDTH) ||
		collideObstacle(destinationRectangle, playerHB, rect, velX))
	{
		printf("!!!COLLISION CHECK\n");
		destinationRectangle.x -= velX - 1.0f;
		
		playerHB.x = destinationRectangle.x;
	}
}

bool ClCollider::collideObstacle(SDL_Rect &destinationRectangle,SDL_Rect &playerHB, SDL_Rect &rect, float&velX)
{
	//---------------------
	// Player's collision
	//---------------------
	int l1 = destinationRectangle.x;
	int r1 = destinationRectangle.x + destinationRectangle.w;
	//int vel1 = playerHB.x - 1;
	
	//-----------
	// Obstacle
	//-----------
	int l2 = rect.x;
	int r2 = rect.x + rect.w;
	
	//-------------------------------------------
	// Return condition if there's a collision 
	// between the Player and another object
	//-------------------------------------------
	if (r1 <= l2)									// if there's NOT Player's right side and left side of another Object
	{
		return false;
	}

	if (l1 >= r2)									// if there's NOT Player's left side and right side of another Object
	{
		return false;
	}
	printf("!OnCollide\n");
	return true;
}

ClPlayer* ClCollider::get_player()
{
	return player;
}

ClObstacle* ClCollider::get_obstacle()
{
	return obstacle;
}