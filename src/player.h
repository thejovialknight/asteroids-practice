#pragma once
#include "entity.h"
#include "input.h"
#include "bullet.h"

std::vector<Line> player_shape();
void control_player(Entity& player, Input& input, std::vector<int>& bullets, std::vector<Entity>& entities, double delta_time);
