#include "world.h"
#include "src/line_explode.h"

void World::init() {
	start_pregame();
}

void World::update(Input& input, double delta_time) {
	if(state == GameState::Game) {
		bool lost_game = false;
		control_player(player_handle, input, bullets, entities, lines, delta_time);
		control_asteroids(lost_game, player_handle, asteroids, entities, exploders, delta_time);
		control_bullet(bullets, asteroids, entities, exploders, delta_time);
		apply_velocities(entities, delta_time);

		if(lost_game) {
			start_postgame();
		}
	}
	else {
		countdown_state(delta_time);
	}

	control_exploders(exploders, delta_time);
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
	exploders.clear();

	// Create player
	player_handle.link(entities, Entity(Vec2(720, 720), 0, Vec2(), player_shape(), lines));

	// Create asteroids
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
	spawn_asteroid(asteroids, entities, lines);
}

void World::start_game() {
	state = GameState::Game;
}

void World::start_postgame() {
	state = GameState::Postgame;
	time_to_next_state = 2;
}
