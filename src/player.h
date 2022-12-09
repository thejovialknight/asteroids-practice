#pragma once
#include "entity.h"
#include "input.h"
#include "bullet.h"
#include "table.h"
#include "handle.h"

std::vector<Line> player_shape();
void control_player(Handle<Entity>& player_handle, Input& input, Table<Handle<Entity>>& bullets, Table<Entity>& entities, Table<Line>& lines, double delta_time);
