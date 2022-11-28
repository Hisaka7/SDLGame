#pragma once
#include "Library.h"

class ClPlayer;

class ClHitbox
{
protected:
    ClPlayer* player;

public:

    ClHitbox();
    ~ClHitbox();

    //============
    // Functions
    //============
    void HitboxUpdate(SDL_Rect& destinationRectangle);      // Update the Positions and the size of the Hitbox

    //=====
    // Set
    //=====
    SDL_Rect playerHB;                          // Player's Hitbox
private:
    
};

