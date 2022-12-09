#pragma once
#include <vector>
#include <iostream>

#include "input.h"
#include "entity.h"
#include "player.h"
#include "bullet.h"
#include "asteroid.h"
#include "collision.h"
#include "line_explode.h"
#include "table.h"
#include "handle.h"

enum GameState {
	Pregame,
	Game,
	Postgame
};

struct World {
	GameState state = GameState::Pregame;
	double time_to_next_state = 2;

	Table<Exploder> exploders;
	Table<Line> lines;

	// Entities and table references
	Table<Entity> entities;
	Handle<Entity> player_handle;
	Table<Handle<Entity>> asteroids;
	Table<Handle<Entity>> bullets;

	void init();
	void update(Input& input, double delta_time);
	void countdown_state(double delta_time);
	void start_pregame();
	void start_game();
	void start_postgame();
};
