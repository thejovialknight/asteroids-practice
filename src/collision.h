#pragma once
#include "entity.h"

bool collision(Entity& a, Entity& b);
bool collision_with_line(Entity& entity, Line& line);
bool intersect(Line& a, Line& b);
