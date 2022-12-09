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

void control_player(Handle<Entity>& player_handle, Input& input, Table<Handle<Entity>>& bullets, Table<Entity>& entities, Table<Line>& lines, double delta_time) {
	// Config
	const double rotation_speed = 4;
	const double acceleration = 200;
	const double max_speed = 300;
	const double window_buffer = 12;

	Entity& player = player_handle.unwrap();

	screen_wrap(player, window_buffer);

	// Movement
	if(input.left.held) {
		player.rotate(-rotation_speed * delta_time);
	}
	if(input.right.held) {
		player.rotate(rotation_speed * delta_time);
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
		if(abs(player.velocity.magnitude()) < 10) {
			player.velocity = Vec2();
		}
	}
	
	// Shoot 
	if(input.shoot.just_pressed) {
		shoot(player, bullets, entities, lines);
	}
}
