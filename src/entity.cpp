#include "entity.h"

Vec2 Entity::forward_unit_vector() {
	return Vec2(cos(rotation), sin(rotation));
}

void apply_velocities(std::vector<Entity>& entities, double delta_time) {
	for(Entity& entity : entities) {
		entity.position.x = entity.position.x + (entity.velocity.x * delta_time);
		entity.position.y = entity.position.y + (entity.velocity.y * delta_time);
	}
}

