#pragma once
#include "IShape.h"
#include <vector>
using namespace std;
//C(t) = (x0 + a * cos(t), y0 + b * sin(t))
//C'(t) = (-a * sin(t), b * cos(t))
class Ellipse : IShape
{
private:
	float minor_radius;
	float major_radius;
public:
	vector<float> firstDerivative(float t) const override;
	vector<float> getPoint(float t) const override;
};

