#include "Library.h"


ClCollectObj::ClCollectObj()
    :core(new ClCore())
{
    redSpY = core->WINDOW_HEIGHT;
    graySpY = core->WINDOW_HEIGHT;
    greenSpY = core->WINDOW_HEIGHT;
}

void ClCollectObj::initCollObj(SDL_Renderer* rR)
{

    //------------
    // Load Data
    //------------
    objRedSrfc = IMG_Load("IMG\\red.png");
    objGraySrfc = IMG_Load("IMG\\gray.png");
    objGreenSrfc = IMG_Load("IMG\\green.png");

    //-----------------
    // Create Surface
    //-----------------
    tRed = SDL_CreateTextureFromSurface(rR, objRedSrfc);
    tGray = SDL_CreateTextureFromSurface(rR, objGraySrfc);
    tGreen = SDL_CreateTextureFromSurface(rR, objGreenSrfc);
}

ClCollectObj::~ClCollectObj()
{
    SDL_FreeSurface(objRedSrfc);
    SDL_FreeSurface(objGraySrfc);
    SDL_FreeSurface(objGreenSrfc);
}

void ClCollectObj::spawnRandomizer(const int WINDOW_WIDTH)
{
    srand(time(NULL));

    redSpX = rand() % WINDOW_WIDTH -20;
    graySpX = rand() % WINDOW_WIDTH - 20;
    greenSpX = rand() % WINDOW_WIDTH - 20;
}

void ClCollectObj::fallGravity()
{
    //redVelY = ;
}

void ClCollectObj::patternManager()
{

}


void ClCollectObj::update(SDL_Renderer* rR)
{
    SDL_Surface* optimizedSurface = NULL;

    SDL_QueryTexture(tRed, NULL, NULL, &srcRed.w, &srcRed.h);
    SDL_QueryTexture(tGray, NULL, NULL, &srcGray.w, &srcGray.h);
    SDL_QueryTexture(tGreen, NULL, NULL, &srcGreen.w, &srcGreen.h);

    //------------------------------------
    // Image Settings (Coordinates,Size)
    //------------------------------------
    destRed[5].x = redX; destRed[5].y = redSpY - redY;
    destRed[5].w = 30; destRed[5].h = 30;

    destGray[5].x = grayX; destGray[5].y = graySpY - grayY;
    destGray[5].w = 30; destGray[5].h = 30;

    destGreen[5].x = greenX; destGreen[5].y = greenSpY - greenY;
    destGreen[5].w = 30; destGreen[5].h = 30;

    SDL_RenderCopy(rR, tRed, &srcRed, &destRed[5]);
    SDL_RenderCopy(rR, tGray, &srcGray, &destGray[5]);
    SDL_RenderCopy(rR, tGreen, &srcGreen, &destGreen[5]);
}