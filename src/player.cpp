#include <math.h>
#include <iostream>

#include "player.h"

std::vector<Line> player_shape() {
	return {
		Line(0, 0, 8, 8),
		Line(8, 8, 8, 0)
	};
}

void control_player(Entity& player, Input& input, double delta_time) {
	const double rotation_speed = 2;
	const double acceleration = 100;
	const double max_speed = 150;

	if(input.left.held) {
		player.rotation -= rotation_speed * delta_time;
		std::cout << "LEFT!" << std::endl;
	}
	if(input.right.held) {
		player.rotation += rotation_speed * delta_time;
		std::cout << "RIGHT!" << std::endl;
	}
	if(input.thrust.held) {
		Vec2 thrust_direction(cos(player.rotation), sin(player.rotation));
		player.velocity.x += thrust_direction.x * acceleration * delta_time;
		player.velocity.y += thrust_direction.y * acceleration * delta_time;
	}
	else {
		Vec2 unit_velocity = player.velocity.unit();
		player.velocity.x -= unit_velocity.x * acceleration * delta_time;
		player.velocity.y -= unit_velocity.y * acceleration * delta_time;
	}
	if(input.shoot.just_pressed) {
		// shoot
	}
}
