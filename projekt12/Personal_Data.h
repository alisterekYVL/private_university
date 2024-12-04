#pragma once
#include <string>
#include <vector>

namespace ap {
	struct PersonalData{
		std::string firsrName;
		std::string lastName;
		int age = 0;
	};

	void Show(const PersonalData& pd);
	void Show(const PersonalData* pd);

	struct PersonalData1 {
		std::string firsrName;
		std::string lastName;
		int age;
	};

	void Show(const PersonalData1& pd1);
	void Show(const PersonalData1* pd1);

	struct PersonalData2 {
		std::string firsrName;
		std::string lastName;
		int age;
	};
	void Show(const PersonalData2& pd2);
	void Show(const PersonalData2* pd2);

	bool SaveStructToFile(const std::string& fileName, const std::vector<PersonalData2>& v) {
		ofstream out(fileName);
		if (out) {
			for (const auto& el : v) {
				out << el.firsrName << el.lastName << endl;
			}
			out.close();
			return true;
		}
		return false;
	}

	std::vector<PersonalData2> ReadStructFromFile(const std::string& fileName) {

	}
}