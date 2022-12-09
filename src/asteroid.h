#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include "entity.h"
#include "config.h"
#include "collision.h"
#include "line_explode.h"
#include "table.h"
#include "handle.h"

void spawn_asteroid(Vec2 position, Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Line>& lines);
void spawn_asteroid(Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Line>& lines);
std::vector<Line> asteroid_shape();
void control_asteroids(bool& out_lost_game, Handle<Entity>& player_handle, Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Exploder>& exploders, double delta_time);

