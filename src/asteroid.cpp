#include "asteroid.h"
#include "src/config.h"

// Spawns asteroid at particular point
void spawn_asteroid(Vec2 position, Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Line>& lines) {
	int max_speed = 100;
	asteroids.add(Handle(entities, Entity(
		position, 
		rand() % 1000, 
		Vec2(
			(rand() % max_speed) - (double)max_speed / 2, 
			(rand() % max_speed) - (double)max_speed / 2
		),
		asteroid_shape(),
		lines
	)));
}

// Randomly spawns asteroid on edges of map
void spawn_asteroid(Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Line>& lines) {
	const double window_buffer = 32;
	int spawn_side = (rand() % 3) + 1;
	int spawn_location;
	switch(spawn_side) {
		case 0: // Left
			spawn_location = rand() % WINDOW_HEIGHT;
			spawn_asteroid(Vec2(-window_buffer, spawn_location), asteroids, entities, lines);
			break;
		case 1: // Right
			spawn_location = rand() % WINDOW_HEIGHT;
			spawn_asteroid(Vec2(WINDOW_WIDTH + window_buffer, spawn_location), asteroids, entities, lines);
			break;
		case 2: // Top
			spawn_location = rand() % WINDOW_WIDTH;
			spawn_asteroid(Vec2(spawn_location, -window_buffer), asteroids, entities, lines);
			break;
		case 3: // Bottom
			spawn_location = rand() % WINDOW_WIDTH;
			spawn_asteroid(Vec2(spawn_location, WINDOW_HEIGHT + window_buffer), asteroids, entities, lines);
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

void control_asteroids(bool& out_lost_game, Handle<Entity>& player_handle, Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Exploder>& exploders, double delta_time) {
	const double rotation_speed = 2;
	
	Entity& player = player_handle.unwrap(); 

	for(int i = 0; i < asteroids.size(); ++i) {
		Handle<Entity>& asteroid_handle = asteroids.at(i);
		Entity& asteroid = asteroid_handle.unwrap();

		asteroid.rotate(rotation_speed * delta_time);
		screen_wrap(asteroid, 32);
		
		if(collision(asteroid, player)) {
			explode_entity(exploders, player_handle);
			explode_entity(exploders, asteroid_handle);
			destroy_entity(asteroid_handle);
			destroy_entity(player_handle);
			asteroids.remove(i);
			out_lost_game = true;
		}
	}
}
