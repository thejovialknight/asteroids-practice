#pragma once
#include <vector>
#include <cstdlib>
#include "entity.h"
#include "config.h"

void spawn_asteroid(Vec2 position, std::vector<int>& asteroids, std::vector<Entity>& entities);
void spawn_asteroid(std::vector<int>& asteroids, std::vector<Entity>& entities);
std::vector<Line> asteroid_shape();
void control_asteroids(std::vector<int>& asteroids, std::vector<Entity>& entities, double delta_time);
