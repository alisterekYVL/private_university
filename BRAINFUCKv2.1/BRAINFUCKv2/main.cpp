#include "BRAINFUCKv2.hpp"
#include <iostream>

int main() {
    BrainfuckInterpreter interpreter;

  
    if (!interpreter.wczytajProgram("kod.txt")) {
        std::cerr << "Blad: Nie mozna otworzyc pliku kod.txt!" << std::endl;
        return 1;
    }


    interpreter.wykonajProgram(std::cout);

    return 0;
}