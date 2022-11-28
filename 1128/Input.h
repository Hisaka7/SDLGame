#pragma once

#include "Library.h"

#define NUM_KEYS 2014



class ClInput
{
	//enum { UP, DOWN, LEFT, RIGHT }dir;
	
	const Uint8* key_states;
	
	bool key_down_event[NUM_KEYS];

	bool check_for_quit(SDL_Event event);

public:
	ClInput();
	
	//============
	// Functions
	//============
	void update();
	bool is_key_down(int key);
	bool is_key_down_event(int key);
	bool quit;
	bool get_quit();
};