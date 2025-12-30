#include <iostream>
#include "FileReader.h"
int main()
{
	const float t = 3.141593f / 4.0f;
	FileReader fr;

    auto curves = fr.readFromFile("../curves_to_check.txt");
    for (const auto& c : curves) {
		std::vector<float>point = c->getPoint(t);
        std::vector<float>derivative = c->firstDerivative(t);
        std::cout << "ID=" << c->getId()
            << " name=" << c->getName()
			<< " Point(PI/4)=(" << point[0] << ", " << point[1] << ", " << point[2] << ")"
			<< " Derivative(PI/4)=(" << derivative[0] << ", " << derivative[1] << ", " << derivative[2] << ")"
            << "\n";
    }
}

