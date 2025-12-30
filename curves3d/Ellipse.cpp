#include "Ellipse.h"

Ellipse::Ellipse(int64_t id, const string& name, float x, float y, float z, float minor_radius, float major_radius) 
    : IShape(id, name, x, y, z), minor_radius(minor_radius), major_radius(major_radius) { }

vector<float> Ellipse::firstDerivative(float t) const
{
    return vector<float>();
}

vector<float> Ellipse::getPoint(float t) const
{
    return vector<float>();
}
