#include "FileReader.h"

vector<unique_ptr<IShape>> FileReader::readFromFile(const char* file_name)
{
	string line;
	vector<unique_ptr<IShape>> result;

	file.open(file_name, ios_base::in);

	if (!file.is_open()) {
		cerr << "failed open file!";
		return result;
	}

	int size = 0;
	if (!(file >> size)) {
		cerr << "failed read size!\n";
		return result;
	}
	std::cout << "DBG: size=" << size << "\n";

	//Обработка всего что есть в файле
	for (int i = 0; i < size; i++)
	{
		char type;
		int64_t id;
		string name;
		float x, y, z;

		if (!(file >> type >> id >> quoted(name) >> x >> y >> z)) {
			cerr << "failed read record header at i=" << i << "\n";
			break;
		}
		std::cout << "DBG: type=" << type << " id=" << id << " name=" << name << " x=" << x << " y=" << y << " z=" << z;

		switch (type)
		{
		case 'C': {
			float radius;
			if (!(file >> radius)) {
				cerr << "failed read C radius at i=" << i << "\n";
				break;
			}
			std::cout << " radius=" << radius << "\n";
			//TODO:Засунуть в результирующий вектор Circle
			break;
		}
		case 'E': {
			float minor_radius, major_radius;
			if (!(file >> minor_radius >> major_radius)) {
				cerr << "failed read E params at i=" << i << "\n";
				break;
			}
			std::cout << " minor radius=" << minor_radius << " major radius=" << major_radius << "\n";
			//TODO:Засунуть в результирующий вектор Ellipse
			break;
		}
		case 'H': {
			float radius, step_for_helix;
			if (!(file >> radius >> step_for_helix)) {
				cerr << "failed read H params at i=" << i << "\n";
				break;
			}
			std::cout << " radius=" << radius << " step_for_helix=" << step_for_helix << "\n";
			//TODO:Засунуть в результирующий вектор Helix
			break;
		}
		default:
			cerr << "unknown shape type: " << type << " at i=" << i << "\n";
			break;
		}
	}

	file.close();
	return result;
}
