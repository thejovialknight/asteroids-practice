#include "world.h"
#include "player.h"
#include "src/entity.h"

#include <iostream>

void World::init() {
	entities.emplace_back(Entity(Vec2(720, 720), 0, Vec2(), player_shape()));
	player_index = 0;

	for(Entity& asteroid : asteroids) {
		entities.push_back(asteroid);
	}
}

void World::update(Input& input, double delta_time) {
	control_player(entities[player_index], input, delta_time);
	apply_velocities(entities, delta_time);

	for(int i = 0; i < entities.size(); i++) {
		std::cout << "Entity[" << i << "] rotation: " << entities[i].rotation << std::endl;
		std::cout << "Entity[" << i << "] x velocity: " << entities[i].velocity.x << std::endl;
		std::cout << "Entity[" << i << "] x position: " << entities[i].position.x << std::endl;
	}
}
