#pragma once
#include <vector>
#include <string>
class IShape
{
private:
	int64_t id;
	std::string name;
	float x, y, z;

public:
	virtual float firstDerivative(float t) const;
	virtual std::vector<float> getPoint() const;
	virtual void setPoint() const;
};

