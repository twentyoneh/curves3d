#include "Circle.h"

Circle::Circle(int64_t id, const string& name, float x, float y, float z, float radius)
	: IShape(id, name, x, y, z), radius(radius) { }

vector<float> Circle::firstDerivative(float t) const
{
	return vector<float>();
}

vector<float> Circle::getPoint(float t) const
{
	return vector<float>();
}
