#include <iostream>
#include "FileReader.h"
int main(int argc, char* argv[])
{

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_curves_file>\n";
        std::cerr << "Example: " << argv[0] << " ../curves_to_check.txt\n";
        return 1;
    }

    const char* path = argv[1];
	FileReader fr;

    auto curves = fr.readFromFile(path);
    for (const auto& c : curves) {
		std::vector<float>point = c->getPoint(t);
        std::vector<float>derivative = c->firstDerivative(t);
        std::cout << "ID=" << c->getId()
            << " name=" << c->getName()
			<< " Point(PI/4)=(" << point[0] << ", " << point[1] << ", " << point[2] << ")"
			<< " Derivative(PI/4)=(" << derivative[0] << ", " << derivative[1] << ", " << derivative[2] << ")"
            << "\n";
    }

    std::vector<const Circle*> circles;
    circles.reserve(curves.size());

    for (const auto& s : curves) {
		if (auto* c = dynamic_cast<const Circle*>(s.get())) {
            circles.push_back(c);
        }
    }

    for (size_t i = 0; i + 1 < circles.size(); ++i) {
        for (size_t j = 0; j + 1 < circles.size() - i; ++j) {
            if (circles[j]->getRadius() > circles[j + 1]->getRadius()) {
                std::swap(circles[j], circles[j + 1]);
            }
        }
    }

    std::cout << "Sotred circles vector: \n";
    for (const auto& c : circles) {
        std::cout << "ID=" << c->getId()
            << " name=" << c->getName()
            << " radius=" << c->getRadius() 
            << "\n";
    }
    
    float sum = 0;
    for (int i = 0; i < circles.size(); i++)
    {
        sum += circles[i]->getRadius();
    }
    std::cout << "Sum of the radii = " << sum;

    return 0;
}

