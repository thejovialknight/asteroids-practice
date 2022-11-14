#include <math.h>
#include "vec2.h"

double Vec2::magnitude() {
	double sum = x * x + y * y;
	return sqrt(sum);
}

Vec2 Vec2::unit() {
	double magnitude = this->magnitude();
	if(magnitude == 0) return Vec2(0, 0);
	return Vec2(x / magnitude, y / magnitude);
}
