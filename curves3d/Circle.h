#pragma once
#include "IShape.h"
#include <vector>
using namespace std;

//C(t) = (x0 + R cos(t), y0 + R sin(t), z0)
//C'(t) = (-R sin(t), R cos(t), 0)
class Circle : IShape
{
private:
	float radius;
public:
	vector<float> firstDerivative(float t) const override;
	vector<float> getPoint(float t) const override;
};

