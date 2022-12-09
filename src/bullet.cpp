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

void shoot(Entity& player, Table<Handle<Entity>>& bullets, Table<Entity>& entities, Table<Line>& lines) {
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
	bullets.add(Handle(entities, Entity(
		position,
		0,
		velocity,
		bullet_shape(),
		lines
	)));
}

void control_bullet(Table<Handle<Entity>>& bullets, Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Exploder>& exploders, double delta_time) {
	for(int i = 0; i < bullets.size(); ++i) {
		Handle<Entity>& bullet_handle = bullets.at(i);
		Entity& bullet = bullet_handle.unwrap();

		Line trajectory(bullet.position, bullet.position + bullet.velocity * delta_time);
		for(int asteroid_index = 0; asteroid_index < asteroids.size(); ++asteroid_index) {
			Handle<Entity>& asteroid_handle = asteroids.at(asteroid_index);
			Entity& asteroid = asteroid_handle.unwrap();
			if(collision_with_line(asteroid, trajectory)) {
				explode_entity(exploders, asteroid_handle);
				explode_entity(exploders, bullet_handle);
				destroy_entity(bullet_handle);
				destroy_entity(asteroid_handle);
				bullets.remove(i);
				asteroids.remove(asteroid_index);
			}
		}

		if(
			bullet.position.x < 0 ||
			bullet.position.x > WINDOW_WIDTH ||
			bullet.position.y < 0 ||
		 	bullet.position.y > WINDOW_HEIGHT
		) {
			destroy_entity(bullet_handle);
			bullets.remove(i);
		}
	}
}
