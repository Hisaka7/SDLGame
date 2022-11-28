#pragma once
#include "Library.h"

class ClPlayer;
class ClObstacle;
class ClHitbox;

class ClCollider
{
protected:
    ClPlayer* player;
    ClObstacle* obstacle;
    ClHitbox* hitbox;

public:
    ClCollider();
    ~ClCollider();

    //============
    // Functions
    //============

    bool playerHitbox();           
    void collideScreen(float& velX, const int WINDOW_WIDTH, 
        SDL_Rect& destinationRectangle, SDL_Rect& playerHB, SDL_Rect& rect);    // Operate when it Collides
    bool collideObstacle(SDL_Rect& destinationRectangle,SDL_Rect &playerHB,
                        SDL_Rect &rect, float&velX);                            // Indicate when the Collider is true

    //=====
   // Set
   //======
    ClPlayer* get_player();
    ClObstacle* get_obstacle();
};
