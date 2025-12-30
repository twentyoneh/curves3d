#include "Ellipse.h"

Ellipse::Ellipse(int64_t id, const string& name, float x, float y, float z, float minor_radius, float major_radius) 
    : IShape(id, name, x, y, z), minor_radius(minor_radius), major_radius(major_radius) { }

vector<float> Ellipse::firstDerivative(float t) const
{
	float x_ = -major_radius * sin(t);
	float y_ = minor_radius * cos(t);
	return vector<float>{x_, y_, 0};
}

vector<float> Ellipse::getPoint(float t) const
{
	float x_ = x + major_radius * cos(t);
	float y_ = y + minor_radius * sin(t);
    return vector<float>{x_, y_, z};
}
