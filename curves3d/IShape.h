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
	IShape(int64_t id, const std::string& name, float x, float y, float z)
		: id(id), name(name), x(x), y(y), z(z) { }
	virtual std::vector<float> firstDerivative(float t) const;
	virtual std::vector<float> getPoint(float t) const;
	
	string getName() const {
		return name;
	}
	int64_t getId() const {
		return id;
	}
};

