#include "world.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"

#include <iostream>

void World::init() {
	entities.emplace_back(Entity(Vec2(720, 720), 0, Vec2(), player_shape()));
	player_index = 0;

	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
	spawn_asteroid(asteroids, entities);
}

void World::update(Input& input, double delta_time) {
	control_player(entities[player_index], input, bullets, entities, delta_time);
	control_asteroids(asteroids, entities, delta_time);
	control_bullet(bullets, entities);
	apply_velocities(entities, delta_time);
}
