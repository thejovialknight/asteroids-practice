#include "line_explode.h"
#include "src/entity.h"

void explode_entity(Table<Exploder>& exploders, Handle<Entity>& entity_handle) {
	Entity& entity = entity_handle.unwrap();
	for(Handle<Line>& line_handle : entity.line_handles.values) {
		exploders.add(Exploder(line_handle));
	}
	entity_handle.release();
}

void control_exploders(Table<Exploder>& exploders, double delta_time) {
	for(int i = 0; i < exploders.size(); ++i) {
		Exploder& exploder = exploders.at(i);
		Line& line = exploder.line_handle.unwrap();

		exploder.time_to_destroy -= delta_time;
		if(exploder.time_to_destroy < 0) {
			exploder.line_handle.release();
			exploders.remove(i); return;
		}

		// Move line
		line.start = line.start + exploder.velocity * delta_time;
		line.end = line.end + exploder.velocity * delta_time;

		// Rotate line
		Vec2 line_vector = line.start - line.end;
		Vec2 origin = line.start + line_vector * 0.5;
		line = line_about_origin(line, origin, exploder.rotation * delta_time);
	} 
}
