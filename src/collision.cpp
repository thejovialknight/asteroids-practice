#include "collision.h"
#include "src/entity.h"

bool collision(Entity& a, Entity& b) {
	for(Handle<Line>& line_handle_a : a.line_handles.values) {
		Line& line_a = line_handle_a.unwrap();
		for(Handle<Line>& line_handle_b : b.line_handles.values) {
			Line& line_b = line_handle_b.unwrap();
			if(intersect(line_a, line_b)){
				return true;
			}
		}
	}

	return false;
}

bool collision_with_line(Entity& entity, Line& line) {
	for(Handle<Line>& entity_line_handle : entity.line_handles.values) {
		Line& entity_line = entity_line_handle.unwrap();
		if(intersect(line, entity_line)) {
			return true;
		}
	}
	
	return false;
}

// Checks if two lines intersect, return false if lines are collinearly overlapping
bool intersect(Line& a, Line& b) {
	// Vec2 intersection; // If we need the intersection point
	Vec2 a_vec = a.end - a.start;
	Vec2 b_vec = b.end - b.start;
	double a_b_cross = cross(a_vec, b_vec);
	Vec2 start_difference = b.start - a.start;
	double a_b_cross_a_vec = cross(start_difference, a_vec);

	// If a_vec X b_vec = 0 and (b.start - a.start) X a_vec = 0, then two lines are collinear
	if(is_zero(a_b_cross) && is_zero(a_b_cross_a_vec)) {
		return false;
	}

	// If a_vec X b_vec = 0 and (b.start - a.start) X a_vec != 0, then two lines are parallel and non intersecting
	if(is_zero(a_b_cross) && !is_zero(a_b_cross_a_vec)) {
		return false;
	}

	// t = (b.start - a.start) X b_vec / (a_vec X b_vec)
	double t = cross(start_difference, b_vec) / a_b_cross;

	// u = (b.start - a.start) X a_vec / (a_vec X b_vec
	double u = cross(start_difference, a_vec) / a_b_cross;

	// If a_vec X b_vec != 0 and 0 <= t <= 1 and 0 <= u <= 1
	if(!is_zero(a_b_cross) && (0 <= t && t <= 1) && (0 <= u && u <= 1)) {
		// intersection = a.start + t * a_vec; // If we need intersection point
		return true;
	}

	// Otherwise, the two line segments are not parallel but do not intersect
	return false;
}

