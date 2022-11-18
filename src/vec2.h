#pragma once
#include "epsilon.h"

struct Vec2 {
	double x = 0;
	double y = 0;

	Vec2() { x = 0; y = 0; }
	Vec2(double x, double y) : x(x), y(y) {}

	double magnitude();
	Vec2 unit();
};

double cross(Vec2& a, Vec2& b);

Vec2 operator -(const Vec2& a, const Vec2& b);
Vec2 operator +(const Vec2& a, const Vec2& b);
double operator *(const Vec2& a, const Vec2& b);
Vec2 operator *(const Vec2& a, const double& t);
Vec2 operator *(const double& t, const Vec2& a);
