#include "IShape.h"

IShape::IShape(int64_t id, const std::string& name, float x, float y, float z)
	: id(id), name(name), x(x), y(y), z(z) {
}

int64_t IShape::getId() const { return id; }

std::string IShape::getName() const { return name; }