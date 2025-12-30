#pragma once
#include "IShape.h"
#include <vector>
#include <cmath>
using namespace std;
//C(t) = (x0 + a * cos(t), y0 + b * sin(t))
//C'(t) = (-a * sin(t), b * cos(t))
class Ellipse : public IShape
{
private:
	float minor_radius;
	float major_radius;
public:
	Ellipse(int64_t id, const string& name, float x, float y, float z, float minor_radius, float major_radius);
	vector<float> firstDerivative(float t) const override;
	vector<float> getPoint(float t) const override;
};

