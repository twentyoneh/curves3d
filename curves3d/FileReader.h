#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>
#include "IShape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
using namespace std;

class FileReader
{
private:
	ifstream file;

public:
	vector<unique_ptr<IShape>> readFromFile(const char* file_name);

};

