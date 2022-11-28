#pragma once
#include "Library.h"

class ClFpsCounter
{
protected:
    Uint64 ticks = SDL_GetTicks();
    Uint64 start = SDL_GetTicks();
    Uint64 end = SDL_GetTicks();

public:
    ClFpsCounter();
    ~ClFpsCounter(void);

    float newtime = start;
    float oldtime = end;
    float delta = 0.10f;
    float currentFrame = int((SDL_GetTicks() / 100) % 6);
    float frameTime = SDL_GetTicks() - start;
    const int FPS = 60;
    const int DELAY_TIME = 1000.0f / FPS;

    float elapsedMS;
    void CapFrameRate();
};