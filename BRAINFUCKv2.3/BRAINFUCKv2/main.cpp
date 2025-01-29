#include "BRAINFUCKv2.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief G³ówna funkcja programu.
 *
 * Program interpretuje kod Brainfuck wczytany z pliku wejœciowego i wypisuje wynik do pliku wyjœciowego.
 *
 * @param argc Liczba argumentów przekazanych do programu.
 * @param argv Tablica argumentów przekazanych do programu.
 * @return int Kod zakoñczenia programu.
 */

int main(int argc, char* argv[]) {
    std::string plikWejsciowy;  // Œcie¿ka do pliku wejœciowego
    std::string plikWyjsciowy;  // Œcie¿ka do pliku wyjœciowego 

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-i" && i + 1 < argc) {
            plikWejsciowy = argv[i + 1];
            i++;
        }
        else if (arg == "-o" && i + 1 < argc) {
            plikWyjsciowy = argv[i + 1];
            i++;
        }
        else {
            std::cout << "Nieznany argument lub brak wartoœci: " << arg << std::endl;
            std::cout << "U¿ycie: " << argv[0] << " -i plik_wejsciowy [-o plik_wyjsciowy]" << std::endl;
            return 1;  // Zakoñcz program z b³êdem
        }
    }

    // Sprawdzenie, czy podano plik wejœciowy
    if (plikWejsciowy.empty()) {
        std::cout << "B³¹d: Nie podano pliku wejœciowego!" << std::endl;
        std::cout << "U¿ycie: " << argv[0] << " -i plik_wejsciowy [-o plik_wyjsciowy]" << std::endl;
        return 1;  // Zakoñcz program z b³êdem
    }

    BrainfuckInterpreter interpreter;

    // Wczytanie programu Brainfuck
    if (!interpreter.wczytajProgram(plikWejsciowy)) {
        std::cout << "B³¹d: Nie mo¿na otworzyæ pliku " << plikWejsciowy << "!" << std::endl;
        return 1;  // Zakoñcz program z b³êdem
    }

    // Wykonanie programu Brainfuck
    if (plikWyjsciowy.empty()) {
        interpreter.wykonajProgram(std::cout);
    }
    else {
        std::ofstream plikWy(plikWyjsciowy);
        if (!plikWy) {
            std::cout << "B³¹d: Nie mo¿na otworzyæ pliku wyjœciowego " << plikWyjsciowy << "!" << std::endl;
            return 1;  // Zakoñcz program z b³êdem
        }
        interpreter.wykonajProgram(plikWy);
        plikWy.close();
    }

    return 0;  // Zakoñcz program
}