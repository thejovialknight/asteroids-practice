#include "entity.h"

void destroy_entity(Handle<Entity>& entity_handle) {
	Entity& entity = entity_handle.unwrap();
	for(Handle<Line>& line_handle : entity.line_handles.values) {
		line_handle.release();
	}
	entity_handle.release();
}

Vec2 Entity::forward_unit_vector() {
	return Vec2(cos(rotation), sin(rotation));
}

void Entity::rotate(double radians) {
	rotation += radians;
	for(int i = 0; i < line_handles.size(); ++i) {
		Line& line = line_handles.at(i).unwrap();
		line = line_about_origin(shape[i], position, rotation);
	}
}

void apply_velocities(Table<Entity>& entities, double delta_time) {
	for(Entity& entity : entities.values) {
		Vec2 move_vector = entity.velocity * delta_time;
		entity.position = entity.position + move_vector;
		for(Handle<Line>& line_handle : entity.line_handles.values) {
			Line& line = line_handle.unwrap();
			line.start = line.start + move_vector;
			line.end = line.end + move_vector;
		}
	}
}

void screen_wrap(Entity& entity, double window_buffer) {
	if(entity.position.x < 0 - window_buffer) entity.position.x = WINDOW_WIDTH + window_buffer;
	if(entity.position.x > WINDOW_WIDTH + window_buffer) entity.position.x = 0 - window_buffer;
	if(entity.position.y < 0 - window_buffer) entity.position.y = WINDOW_HEIGHT + window_buffer;
	if(entity.position.y > WINDOW_HEIGHT + window_buffer) entity.position.y = 0 - window_buffer;
}

Line line_about_origin(Line& line, Vec2& origin, double rotation) {
	return Line(
		(line.start.x * cos(rotation) - line.start.y * sin(rotation)) + origin.x,
		(line.start.y * cos(rotation) + line.start.x * sin(rotation)) + origin.y,
		(line.end.x * cos(rotation) - line.end.y * sin(rotation)) + origin.x,
		(line.end.y * cos(rotation) + line.end.x * sin(rotation)) + origin.y
	);
}
