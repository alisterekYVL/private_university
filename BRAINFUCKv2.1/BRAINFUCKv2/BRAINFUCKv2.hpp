#include <string>
#include <vector>
#include <iostream>

class BrainfuckInterpreter {
public:
    BrainfuckInterpreter();
    bool wczytajProgram(const std::string& nazwaPliku); 
    void wykonajProgram(std::ostream& wyjscie = std::cout); 

private:
    std::vector<unsigned char> memory; 
    size_t pointer; 
    std::vector<char> program; 
};