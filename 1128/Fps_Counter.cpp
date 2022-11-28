#include "Library.h"


ClFpsCounter::ClFpsCounter()
{

}

ClFpsCounter::~ClFpsCounter(void)
{

}

void ClFpsCounter::CapFrameRate()
{
    start;
    end;
    elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

    SDL_Delay(floor(16.6f - elapsedMS));                                       // Caps the framerate. Smaller is faster, Bigger is slower
}