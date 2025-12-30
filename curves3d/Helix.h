#pragma once
#include "IShape.h"
using namespace std;

//C(t) = (x0 + R cos(t), y0 + R sin(t), z0 + (step_for_helix * t) / (2 * pi))
//C'(t) = (-R sin(t), R cos(t), step_for_helix / (2 * pi))
class Helix : public IShape
{
private:
	float radius;
	float step;
public:
	Helix(int64_t id, const string& name, float x, float y, float z, float radius, float step);
	vector<float> firstDerivative(float t) const override;
	vector<float> getPoint(float t) const override;
};

