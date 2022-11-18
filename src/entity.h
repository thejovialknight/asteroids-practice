#pragma once
#include <vector>
#include <math.h>

#include "vec2.h"
#include "config.h"

struct Line {
	Vec2 start;
	Vec2 end;

	Line(Vec2 start, Vec2 end) : start(start), end(end) {}
	Line(double ax, double ay, double bx, double by) {
		start = Vec2(ax, ay);
		end = Vec2(bx, by);
	}
};

struct Entity {
	Vec2 position;
	double rotation;
	Vec2 velocity;
	std::vector<Line> lines;

	Entity(Vec2 position, double rotation, Vec2 velocity, std::vector<Line> lines)
		: position(position), rotation(rotation), velocity(velocity), lines(lines) {}

	Vec2 forward_unit_vector();
};

Line offset_line(Vec2& position, Line& line);
void apply_velocities(std::vector<Entity>& entities, double delta_time);
void screen_wrap(Entity& entity, double window_buffer);
