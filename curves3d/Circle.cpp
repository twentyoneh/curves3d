#include "Circle.h"

Circle::Circle(int64_t id, const string& name, float x, float y, float z, float radius)
	: IShape(id, name, x, y, z), radius(radius) { }

vector<float> Circle::firstDerivative(float t) const
{
	float x_ = -radius * sin(t);
	float y_ = radius * cos(t);
	return vector<float>{x_, y_, 0};
}

vector<float> Circle::getPoint(float t) const
{
	float x_ = x + radius * cos(t);
	float y_ = y + radius * sin(t);
	return vector<float>{x_, y_, z};
}
