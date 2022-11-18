#include "world.h"

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

	/*
	std::vector<Line> shape1 = {Line(1, 1, 3, 3)};
	std::vector<Line> shape2 = {Line(1, 2, 3, 0)};
	if(collision(shape1, shape2)) {
		std::cout << collision(shape1, shape2) << std::endl;
	}
	else {
		std::cout << "Nope" << std::endl;
	}
	*/
}

void World::update(Input& input, double delta_time) {
	control_player(entities[player_index], input, bullets, entities, delta_time);
	control_asteroids(player_index, asteroids, entities, delta_time);
	control_bullet(bullets, entities);
	apply_velocities(entities, delta_time);
}
