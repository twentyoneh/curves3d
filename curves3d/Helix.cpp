#include "Helix.h"

Helix::Helix(int64_t id, const string& name, float x, float y, float z, float radius, float step)
	: IShape(id, name, x, y, z), radius(radius), step(step) { }

vector<float> Helix::firstDerivative(float t) const
{
	float x_ = -radius * sin(t);
	float y_ = radius * cos(t);
	float z_ = step / (2 * 3.141593f);
    return vector<float>{x_, y_, z_};
}

vector<float> Helix::getPoint(float t) const
{
	float x_ = x + radius * cos(t);
	float y_ = y + radius * sin(t);
	float z_ = z + (step * t) / (2 * 3.141593f);
	return vector<float>{x_, y_, z_};
}
