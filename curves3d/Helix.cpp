#include "Helix.h"

Helix::Helix(int64_t id, const string& name, float x, float y, float z, float radius, float step)
	: IShape(id, name, x, y, z), radius(radius), step(step) { }

vector<float> Helix::firstDerivative(float t) const
{
    return vector<float>();
}

vector<float> Helix::getPoint(float t) const
{
    return vector<float>();
}
