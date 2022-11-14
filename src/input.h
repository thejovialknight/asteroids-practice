#pragma once
#include <SDL2/SDL.h>
#include <vector>

struct Button {
	bool held = false;
	bool just_pressed = false;
	bool released = false;

	void query_press(SDL_Scancode input, SDL_Scancode expected);
	void query_release(SDL_Scancode input, SDL_Scancode expected);
};

// Structure that represents user input, updated every frame.
struct Input
{
	Button exit;
	Button left;
	Button right;
	Button thrust;
	Button shoot;

	void set();
};

