#include <iostream>
#include <fstream>
#include "Personal_Data.h"
#include <vector>
#include <sstream>
#include <string>

using namespace std;
using Vector = std::vector<double>;

namespace ap {
	void Show(const PersonalData& pd) {
		std::cout << pd.firsrName << " " << pd.lastName << " | " << pd.age << std::endl;
	}

	void Show(const PersonalData* pd) {
		std::cout << pd->firsrName << " " << pd->lastName << " | " << pd->age << std::endl;
	}

	PersonalData ReadPersonalData() {
		PersonalData pd2;
		std::cout << "Imiê: ";
		std::getline(std::cin, pd2.firsrName);
		std::cout << "Nazwisko: ";
		std::getline(std::cin, pd2.lastName);
		std::cout << "Wiek: ";
		std::cin >> pd2.age;
		return pd2;
	}

	void Show(const PersonalData1& pd2) {
		std::cout << "Imie: " << pd2.firsrName;
		std::cout << "Nazwisko: " << pd2.lastName;
		std::cout << "Wiek: " << pd2.age;
	}

	bool SaveStructToFile(const string& fileName, const Vector& v) {
		ofstream out(fileName);
		if (out) {
			for (const auto el : v) {
				out << el << endl;
			}
			out.close();
			return true;
		}
		return false;
	}

	Vector LoadStructFromFile(const string& fileName) {
		Vector v;
		ifstream in(fileName);
		if (in) {
			double x;
			while (in >> x) {
				v.push_back(x);
			}
			in.close();
		}
		return v;
}