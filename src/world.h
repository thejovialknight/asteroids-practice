#pragma once
#include <vector>
#include <iostream>

#include "input.h"
#include "entity.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "collision.h"

enum GameState {
	Pregame,
	Game,
	Postgame
};

struct World {
	GameState state = GameState::Pregame;
	double time_to_next_state = 2;

	std::vector<Entity> entities;

	// Entity references
	int player_index;
	std::vector<int> asteroids;
	std::vector<int> bullets;

	void init();
	void update(Input& input, double delta_time);
	void countdown_state(double delta_time);
	void start_pregame();
	void start_game();
	void start_postgame();
};
