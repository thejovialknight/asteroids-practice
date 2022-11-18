#include "bullet.h"
#include <iostream>

std::vector<Line> bullet_shape() {
	return std::vector<Line> { 
		Line(-1, -1, -1, 1),
		Line(-1, -1, 1, -1),
		Line(-1, 1, 1, 1),
		Line(1, -1, 1, 1)
	};
}

void shoot(Entity& player, std::vector<int>& bullets, std::vector<Entity>& entities) {
	// Config
	const double speed = 300;

	Vec2 player_forward = player.forward_unit_vector();
	Vec2 position(
		player.position.x + player_forward.x * 6,
		player.position.y + player_forward.y * 6
	);
	Vec2 velocity(
		player_forward.x * speed,
		player_forward.y * speed
	);
	entities.emplace_back(Entity(
		position,
		0,
		velocity,
		bullet_shape()
	));
	bullets.emplace_back(entities.size() - 1);
}

void control_bullet(std::vector<int>& bullets, std::vector<int>& asteroids, std::vector<Entity>& entities, double delta_time) {
	for(int& bullet_index : bullets) {
		Entity& bullet = entities[bullet_index];

		Line trajectory(bullet.position, bullet.position + bullet.velocity * delta_time);
		for(int& asteroid_index : asteroids) {
			Entity& asteroid = entities[asteroid_index];
			if(collision_with_line(asteroid, trajectory)) {
				asteroid.lines.clear();
				bullet.position = bullet.position + bullet.velocity * 10000;
			}
		}

		if(
			bullet.position.x < 0 ||
			bullet.position.x > WINDOW_WIDTH ||
			bullet.position.y < 0 ||
		 	bullet.position.y > WINDOW_HEIGHT
		) {
			// destroy the bullet index and entity. Just wait for tables tbh
		}
	}
}
