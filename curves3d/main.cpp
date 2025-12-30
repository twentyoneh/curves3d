#include <iostream>
#include "FileReader.h"
int main()
{
	FileReader fr;

    auto curves = fr.readFromFile("../curves_to_check.txt");

    std::cout << "DBG: curves.size()=" << curves.size() << "\n";

    for (const auto& c : curves) {
        std::cout << "ID=" << c->getId()
            << " name=" << c->getName()
            << "\n";
    }
}

