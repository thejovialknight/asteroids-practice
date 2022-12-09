#pragma once
#include <vector>
#include "vec2.h"
#include "entity.h"
#include "table.h"
#include "handle.h"

struct Exploder {
	Handle<Line> line_handle;
	Vec2 velocity;
	double rotation;
	double time_to_destroy;

	Exploder(Handle<Line> line_handle) : line_handle(line_handle) {
		const int max_velocity = 40;
		const int max_rotational_velocity = 4;
		const int max_countdown = 5;

		velocity = Vec2(
			(rand() % max_velocity) - ((double)max_velocity / 2),
			(rand() % max_velocity) - ((double)max_velocity / 2)
		);
		rotation = (rand() % max_rotational_velocity) - ((double)max_rotational_velocity / 2);
		time_to_destroy = (double)(rand() % (max_countdown * 1000)) / 1000;
	}
};

void explode_entity(Table<Exploder>& exploders, Handle<Entity>& entity_handle);
void control_exploders(Table<Exploder>& exploders, double delta_time);
