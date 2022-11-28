#include "Library.h"


ClHitbox::ClHitbox()
{

}

ClHitbox::~ClHitbox()
{

}

//=======================================
// Player's Hitbox Size and Coordinates
//=======================================
void ClHitbox::HitboxUpdate(SDL_Rect &destinationRectangle)
{
    playerHB.h = destinationRectangle.h;            // Height
    playerHB.w = destinationRectangle.w;            // Width
    playerHB.x = destinationRectangle.x;            // X Coordinate
    playerHB.y = destinationRectangle.y;            // Y Coordinate
}