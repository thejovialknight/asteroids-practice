#pragma once
#include <vector>

#include "vec2.h"

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
};

void apply_velocities(std::vector<Entity>& entities, double delta_time);
