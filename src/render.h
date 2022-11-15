#pragma once
#include <SDL2/SDL.h>

#include "world.h"

void render(SDL_Renderer* renderer, World& world);
Line line_about_origin(Line& line, Vec2& origin, double rotation);
