#include <iostream>
#include <fstream>
#include "Personal_Data.h"
using namespace std;

int main() {
    ap::PersonalData pd{"Jan", "Kowal", 20};
    ap::Show(pd);
    ap::Show(&pd);

    Show(v);
    SaveStructToFile("struct.txt", v);
}
//zapisanie vertora struktiru w pliku
// bool SaveStructToFile(const std::string& fileName, const std::vector<PersonalData>& v)
// odczytywanie structur z pliku
// std::vector<PersonalData> ReadStructFromFile(const std::string& fileName);