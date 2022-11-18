#include "entity.h"

Vec2 Entity::forward_unit_vector() {
	return Vec2(cos(rotation), sin(rotation));
}

Line offset_line(Vec2& position, Line& line) {
	return Line(line.start + position, line.end + position);
}

void apply_velocities(std::vector<Entity>& entities, double delta_time) {
	for(Entity& entity : entities) {
		entity.position.x = entity.position.x + (entity.velocity.x * delta_time);
		entity.position.y = entity.position.y + (entity.velocity.y * delta_time);
	}
}

void screen_wrap(Entity& entity, double window_buffer) {
	if(entity.position.x < 0 - window_buffer) entity.position.x = WINDOW_WIDTH + window_buffer;
	if(entity.position.x > WINDOW_WIDTH + window_buffer) entity.position.x = 0 - window_buffer;
	if(entity.position.y < 0 - window_buffer) entity.position.y = WINDOW_HEIGHT + window_buffer;
	if(entity.position.y > WINDOW_HEIGHT + window_buffer) entity.position.y = 0 - window_buffer;
}
