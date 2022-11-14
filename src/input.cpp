#include "input.h"
#include <SDL2/SDL_scancode.h>

void Button::query_press(SDL_Scancode input, SDL_Scancode expected) {
	if(input == expected) {
		if(!held) {
			just_pressed = true;
		}

		held = true;
	}
}

void Button::query_release(SDL_Scancode input, SDL_Scancode expected) {
	if(input == expected) {
		if(held) {
			released = true;
		}

		held = false;
		just_pressed = false;
	}
}

// Sets the Input data structure based on SDL keyboard events.
void Input::set()
{
	exit.just_pressed = false;
	left.just_pressed = false;
	right.just_pressed = false;
	thrust.just_pressed = false;
	shoot.just_pressed = false;

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			exit.just_pressed = true;
			break;
		case SDL_KEYDOWN:
			exit.query_press(event.key.keysym.scancode, SDL_SCANCODE_ESCAPE);
			left.query_press(event.key.keysym.scancode, SDL_SCANCODE_LEFT);
			right.query_press(event.key.keysym.scancode, SDL_SCANCODE_RIGHT);
			thrust.query_press(event.key.keysym.scancode, SDL_SCANCODE_UP);
			shoot.query_press(event.key.keysym.scancode, SDL_SCANCODE_SPACE);
			break;
		case SDL_KEYUP:
			exit.query_release(event.key.keysym.scancode, SDL_SCANCODE_ESCAPE);
			left.query_release(event.key.keysym.scancode, SDL_SCANCODE_LEFT);
			right.query_release(event.key.keysym.scancode, SDL_SCANCODE_RIGHT);
			thrust.query_release(event.key.keysym.scancode, SDL_SCANCODE_UP);
			shoot.query_release(event.key.keysym.scancode, SDL_SCANCODE_SPACE);
			break;
		}
	}
}

