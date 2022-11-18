#pragma once
#include <vector>
#include <iostream>

#include "input.h"
#include "entity.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "collision.h"

struct World {
	std::vector<Entity> entities;

	// Entity references
	int player_index;
	std::vector<int> asteroids;
	std::vector<int> bullets;

	void init();
	void update(Input& input, double delta_time);
};
