#pragma once
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class FileReader
{
private:
	ifstream file;

public:
	void readFromFile(const char* file_name) {
		string line;

		file.open(file_name, ios_base::in);

		if (!file.is_open()) {
			cerr << "failed open file!";
			return;
		}

		if (!getline(file, line))
			cerr << "failed read file!";
		
		while (getline(file, line)) {
			std::cout << line << std::endl;
		}

		file.close();
	}

};

