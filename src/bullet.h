#pragma once
#include <vector>
#include "entity.h"
#include "config.h"
#include "collision.h"
#include "line_explode.h"
#include "table.h"
#include "handle.h"

std::vector<Line> bullet_shape();
void shoot(Entity& player, Table<Handle<Entity>>& bullets, Table<Entity>& entities, Table<Line>& lines);
void control_bullet(Table<Handle<Entity>>& bullets, Table<Handle<Entity>>& asteroids, Table<Entity>& entities, Table<Exploder>& exploders, double delta_time);
