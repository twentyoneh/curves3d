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

		switch (type)
		{
		case 'C': {
			float radius;
			if (!(file >> radius)) {
				cerr << "failed read C radius at i=" << i << "\n";
				break;
			}
			result.push_back(std::unique_ptr<IShape>(new Circle(id,name,x,y,z,radius)));
			break;
		}
		case 'E': {
			float minor_radius, major_radius;
			if (!(file >> minor_radius >> major_radius)) {
				cerr << "failed read E params at i=" << i << "\n";
				break;
			}
			result.push_back(std::unique_ptr<IShape>(new Ellipse(id, name, x, y, z, minor_radius, major_radius)));
			break;
		}
		case 'H': {
			float radius, step_for_helix;
			if (!(file >> radius >> step_for_helix)) {
				cerr << "failed read H params at i=" << i << "\n";
				break;
			}
			result.push_back(std::unique_ptr<IShape>(new Helix(id, name, x, y, z, radius, step_for_helix)));
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
