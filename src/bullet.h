#pragma once
#include <vector>
#include "entity.h"
#include "config.h"
#include "collision.h"

std::vector<Line> bullet_shape();
void shoot(Entity& player, std::vector<int>& bullets, std::vector<Entity>& entities);
void control_bullet(std::vector<int>& bullets, std::vector<int>& asteroids, std::vector<Entity>& entities, double delta_time);
