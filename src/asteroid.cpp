#include "asteroid.h"
#include "src/config.h"

// Spawns asteroid at particular point
void spawn_asteroid(Vec2 position, std::vector<int>& asteroids, std::vector<Entity>& entities) {
	int max_speed = 100;
	entities.emplace_back(Entity(position, rand() % 1000, Vec2((rand() % max_speed) - (double)max_speed / 2, (rand() % max_speed) - (double)max_speed / 2), asteroid_shape()));
	asteroids.emplace_back(entities.size() -1);
}

// Randomly spawns asteroid on edges of map
void spawn_asteroid(std::vector<int>& asteroids, std::vector<Entity>& entities) {
	const double window_buffer = 32;
	int spawn_side = (rand() % 3) + 1;
	int spawn_location;
	switch(spawn_side) {
		case 0: // Left
			spawn_location = rand() % WINDOW_HEIGHT;
			spawn_asteroid(Vec2(-window_buffer, spawn_location), asteroids, entities);
			break;
		case 1: // Right
			spawn_location = rand() % WINDOW_HEIGHT;
			spawn_asteroid(Vec2(WINDOW_WIDTH + window_buffer, spawn_location), asteroids, entities);
			break;
		case 2: // Top
			spawn_location = rand() % WINDOW_WIDTH;
			spawn_asteroid(Vec2(spawn_location, -window_buffer), asteroids, entities);
			break;
		case 3: // Bottom
			spawn_location = rand() % WINDOW_WIDTH;
			spawn_asteroid(Vec2(spawn_location, WINDOW_HEIGHT + window_buffer), asteroids, entities);
			break;
		default:
			break;
	}
}

std::vector<Line> asteroid_shape() {
	return std::vector<Line> {
		Line(-16, -16, -24, 0),
		Line(-24, 0, -4, 24),
		Line(-4, 24, 24, 0),
		Line(24, 0, 0, -24),
		Line(0, -24, -16, -16)
	};
}

void control_asteroids(bool& out_lost_game, int player_index, std::vector<int>& asteroids, std::vector<Entity>& entities, double delta_time) {
	const double rotation_speed = 2;
	
	Entity& player = entities[player_index];

	for(int& asteroid_index : asteroids) {
		Entity& asteroid = entities[asteroid_index];

		asteroid.rotation += rotation_speed * delta_time;
		screen_wrap(asteroid, 32);
		
		if(collision(asteroid, player)) {
			player.lines.clear();
			out_lost_game = true;
		}
	}

}
