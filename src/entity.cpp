#include "entity.h"

void apply_velocities(std::vector<Entity>& entities, double delta_time) {
	for(Entity& entity : entities) {
		entity.position.x = entity.position.x + (entity.velocity.x * delta_time);
		entity.position.y = entity.position.y + (entity.velocity.y * delta_time);
	}
}
