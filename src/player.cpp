#include <math.h>
#include <iostream>

#include "player.h"
#include "config.h"

std::vector<Line> player_shape() {
	return {
		Line(-12,  8,  12,  0),
		Line(-12, -8,  12,  0),
		Line(-12,  8, -12, -8) 
	};
}

void control_player(Entity& player, Input& input, std::vector<int>& bullets, std::vector<Entity>& entities, double delta_time) {
	// Config
	const double rotation_speed = 2;
	const double acceleration = 100;
	const double max_speed = 150;
	const double window_buffer = 12;

	// Screen wrap
	if(player.position.x < 0 - window_buffer) player.position.x = WINDOW_WIDTH + window_buffer;
	if(player.position.x > WINDOW_WIDTH + window_buffer) player.position.x = 0 - window_buffer;
	if(player.position.y < 0 - window_buffer) player.position.y = WINDOW_HEIGHT + window_buffer;
	if(player.position.y > WINDOW_HEIGHT + window_buffer) player.position.y = 0 - window_buffer;

	// Movement
	if(input.left.held) {
		player.rotation -= rotation_speed * delta_time;
		std::cout << "LEFT!" << std::endl;
	}
	if(input.right.held) {
		player.rotation += rotation_speed * delta_time;
		std::cout << "RIGHT!" << std::endl;
	}
	if(input.thrust.held) {
		Vec2 thrust_direction = player.forward_unit_vector();
		player.velocity.x += thrust_direction.x * acceleration * delta_time;
		player.velocity.y += thrust_direction.y * acceleration * delta_time;
	}
	else {
		Vec2 unit_velocity = player.velocity.unit();
		player.velocity.x -= unit_velocity.x * acceleration * delta_time;
		player.velocity.y -= unit_velocity.y * acceleration * delta_time;
	}
	
	// Shoot 
	if(input.shoot.just_pressed) {
		shoot(player, bullets, entities);
	}
}
