#pragma once
#include <vector>
#include <string>
class IShape
{
private:
	int64_t id;
	std::string name;
protected:
	float x, y, z;

public:
	virtual std::vector<float> firstDerivative(float t) const;
	virtual std::vector<float> getPoint(float t) const;
	
	string getName() const {
		return name;
	}
	int64_t getId() const {
		return id;
	}
};

