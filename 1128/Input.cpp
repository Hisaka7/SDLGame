
#include "Library.h"

//============================
// PRIVATE HELPER FUNCTIONS
//============================

bool ClInput::check_for_quit(SDL_Event event)
{
	if (event.type == SDL_QUIT)
	{
		return true;
	}

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			return true;
			break;
		default:
			break;
		}
	}

	return false;
}

//===================
// PUBLIC FUNCTIONS
//===================

ClInput::ClInput()
{
	key_states = SDL_GetKeyboardState(NULL);		// USED FOR: bool ClInput::is_key_down(int key)

}

bool ClInput::get_quit()
{
	return quit;
}

void ClInput::update()
{
	for (int i = 0; i < NUM_KEYS; i++)
	{
		key_down_event[i] = false;
	}

	key_states = SDL_GetKeyboardState(NULL);

	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		if(check_for_quit(event))						// ESC or X button to close the game
		{
			quit = true;
			printf("Esc is pressed");
		}
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			key_down_event[event.key.keysym.scancode] = true;
			
		}
		if (event.type == SDL_KEYUP)
		{
			key_down_event[event.key.keysym.scancode] = false;
		}
	}
}

bool ClInput::is_key_down(int key)
{
	return key_states[key];					// DO NOT FORGET TO PUT IN THE CONST: key_states = SDL_GetKeyboardState(NULL);
}

bool ClInput::is_key_down_event(int key)
{
	return key_down_event[key];
}

