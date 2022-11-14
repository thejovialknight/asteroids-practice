#include "render.h"
#include <SDL2/SDL_render.h>

void render(SDL_Renderer* renderer, World& world) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for(Entity& entity : world.entities) {
		for(Line& line : entity.lines) {
			SDL_RenderDrawLine(renderer, 
				line.start.x + entity.position.x, 
				line.start.y + entity.position.y, 
				line.end.x + entity.position.x, 
				line.end.y + entity.position.y
			);
		}
	}
	SDL_RenderPresent(renderer);
}
