#pragma once
#include "entity.h"
#include "input.h"

std::vector<Line> player_shape();
void control_player(Entity& player, Input& input, double delta_time);
