#pragma once
#include <vector>
#include "entity.h"
#include "config.h"

std::vector<Line> bullet_shape();
void shoot(Entity& player, std::vector<int>& bullets, std::vector<Entity>& entities);
void control_bullet(std::vector<int>& bullets, std::vector<Entity>& entities);
