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
	IShape(int64_t id, const std::string& name, float x, float y, float z);
	virtual std::vector<float> firstDerivative(float t) const = 0;
	virtual std::vector<float> getPoint(float t) const = 0;
	
	std::string getName() const;
	int64_t getId() const;
};

