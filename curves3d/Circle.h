#pragma once
#include "IShape.h"
#include <vector>
using namespace std;

//C(t) = (x0 + R cos(t), y0 + R sin(t), z0)
//C'(t) = (-R sin(t), R cos(t), 0)
class Circle : public IShape
{
private:
	float radius;
public:
	Circle(int64_t id, const string& name, float x, float y, float z, float radius);
	vector<float> firstDerivative(float t) const override;
	vector<float> getPoint(float t) const override;
	float getRadius() const;
};

