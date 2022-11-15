#include "render.h"

#include <math.h>
#include <SDL2/SDL_render.h>
#include <iostream>

void render(SDL_Renderer* renderer, World& world) {
	std::cout << "Starting render!" << std::endl;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for(Entity& entity : world.entities) {
		for(Line& unrotated_line : entity.lines) {
			Line line = line_about_origin(unrotated_line, entity.position, entity.rotation);
			SDL_RenderDrawLine(renderer, 
				line.start.x + entity.position.x, 
				line.start.y + entity.position.y, 
				line.end.x + entity.position.x, 
				line.end.y + entity.position.y
			);
		}
	}
	SDL_RenderPresent(renderer);

	std::cout << "Rendered!" << std::endl;
}

Line line_about_origin(Line& line, Vec2& origin, double rotation) {
	return Line(
		line.start.x * cos(rotation) - line.start.y * sin(rotation),
		line.start.y * cos(rotation) + line.start.x * sin(rotation),
		line.end.x * cos(rotation) - line.end.y * sin(rotation),
		line.end.y * cos(rotation) + line.end.x * sin(rotation)
	);
}
