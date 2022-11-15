#include <iostream>
#include <SDL2/SDL.h>

#include "input.h"
#include "world.h"
#include "render.h"
#include "config.h"

int main(int argc, char* argv[]) {
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "Error initializing SDL!" << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("pathtrace", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if(!window) {
		std::cout << "Error creating window!" << std::endl;
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer) {
		std::cout << "Error creating renderer!" << std::endl;
		return 1;
	}

	Input input;
	World world;
	world.init();

	bool exit = false;
	while(!exit) {
		std::cout << "Starting loop!" << std::endl;
		input.set();
		if(input.exit.held) { 
			std::cout << "Exit held!" << std::endl;
			exit = true; 
		}
		world.update(input, 0.016);
		render(renderer, world);
		SDL_Delay(16);
		std::cout << "Ending loop!" << std::endl;
		if(exit) std::cout << "With exit!" << std::endl;
	}
}

