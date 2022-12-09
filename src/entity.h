#pragma once
#include <vector>
#include <math.h>

#include "vec2.h"
#include "config.h"
#include "table.h"
#include "handle.h"

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
	Table<Handle<Line>> line_handles;
	std::vector<Line> shape;

	Entity(Vec2 position, double rotation, Vec2 velocity, std::vector<Line> shape, Table<Line>& lines)
	: position(position), rotation(rotation), velocity(velocity), shape(shape) {
		for(Line& line : shape) {
			Line offset_line(line.start + position, line.end + position);
			line_handles.add(Handle(lines, offset_line));
		}
	}

	Vec2 forward_unit_vector();
	void rotate(double rotation);
};

void destroy_entity(Handle<Entity>& entity_handle);
Line offset_line(Vec2& position, Line& line);
void apply_velocities(Table<Entity>& entities, double delta_time);
void screen_wrap(Entity& entity, double window_buffer);
Line line_about_origin(Line& line, Vec2& origin, double rotation);
