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
	const double speed = 150;

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

	std::cout << "Bullet shot at " << position.x << ", " << position.y << " and with velocity " << velocity.x << ", " << velocity.y << "!" << std::endl;
}

void control_bullet(std::vector<int>& bullets, std::vector<Entity>& entities) {
	for(int& bullet_index : bullets) {
		Entity& bullet = entities[bullet_index];
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
