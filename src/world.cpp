#include "world.h"
#include "player.h"
#include "bullet.h"
#include "src/entity.h"

#include <iostream>

void World::init() {
	entities.emplace_back(Entity(Vec2(720, 720), 0, Vec2(), player_shape()));
	player_index = 0;
}

void World::update(Input& input, double delta_time) {
	control_player(entities[player_index], input, bullets, entities, delta_time);
	control_bullet(bullets, entities);
	apply_velocities(entities, delta_time);
}
