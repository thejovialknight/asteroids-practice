#include "render.h"

#include <math.h>
#include <SDL2/SDL_render.h>
#include <iostream>

void render(SDL_Renderer* renderer, World& world) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for(Line& line : world.lines.values) {
		SDL_RenderDrawLine(renderer, 
			line.start.x, 
			line.start.y,
			line.end.x,
			line.end.y
		);
	}
	SDL_RenderPresent(renderer);
}


