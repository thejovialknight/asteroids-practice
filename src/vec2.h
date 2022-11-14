#pragma once

struct Vec2 {
	double x = 0;
	double y = 0;

	Vec2() { x = 0; y = 0; }
	Vec2(double x, double y) : x(x), y(y) {}

	double magnitude();
	Vec2 unit();
};
