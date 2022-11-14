#pragma once
#include <vector>

#include "input.h"
#include "entity.h"
#include "player.h"

struct World {
	std::vector<Entity> entities;

	int player_index;
	std::vector<Entity> asteroids;

	void init();
	void update(Input& input, double delta_time);
};
