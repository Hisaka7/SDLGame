#define SDL_MAIN_HANDLED
#include "Library.h"


int main(int argc, char* argv[])
{
	ClCore pCore;

	pCore.mainLoop();

	return 0;
}