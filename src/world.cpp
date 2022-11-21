#include "world.h"

void World::init() {
	start_pregame();
}

void World::update(Input& input, double delta_time) {
	if(state == GameState::Game) {
		bool lost_game = false;
		control_player(entities[player_index], input, bullets, entities, delta_time);
		control_asteroids(lost_game, player_index, asteroids, entities, delta_time);
		control_bullet(bullets, asteroids, entities, delta_time);
		apply_velocities(entities, delta_time);

		if(lost_game) {
			start_postgame();
		}
	}
	else {
		countdown_state(delta_time);
	}
}

void World::countdown_state(double delta_time) {
	time_to_next_state -= delta_time;
	if(time_to_next_state < 0) {
		// If we are in pregame, start game. If we are in postgame, start pregame
		if(state == GameState::Pregame) { 
			start_game();
		}
		else { 
			start_pregame(); 
		}
	}
}

void World::start_pregame() {
	state = GameState::Pregame;
	time_to_next_state = 2;

	// Clean up data
	entities.clear();
	asteroids.clear();
	bullets.clear();

	// Create player
	entities.emplace_back(Entity(Vec2(720, 720), 0, Vec2(), player_shape()));
	player_index = 0;

	// Create asteroids
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
}

void World::start_game() {
	state = GameState::Game;
}

void World::start_postgame() {
	state = GameState::Postgame;
	time_to_next_state = 2;
}
