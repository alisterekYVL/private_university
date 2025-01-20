#include "BRAINFUCKv2.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief G³ówna funkcja programu.
 *
 * Program interpretuje kod Brainfuck wczytany z pliku wejœciowego i wypisuje wynik na standardowe wyjœcie lub do pliku wyjœciowego.
 *
 * @param argc Liczba argumentów przekazanych do programu.
 * @param argv Tablica argumentów przekazanych do programu.
 * @return int Kod zakoñczenia programu (0 w przypadku sukcesu, 1 w przypadku b³êdu).
 */
int main(int argc, char* argv[]) {
    std::string plikWejsciowy;  // Œcie¿ka do pliku wejœciowego z kodem Brainfuck
    std::string plikWyjsciowy;  // Œcie¿ka do pliku wyjœciowego (opcjonalnie)

    // Rêczne parsowanie argumentów linii poleceñ
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-i" && i + 1 < argc) {
            plikWejsciowy = argv[i + 1];  // Ustaw œcie¿kê do pliku wejœciowego
            i++; // Przeskocz do nastêpnego argumentu
        }
        else if (arg == "-o" && i + 1 < argc) {
            plikWyjsciowy = argv[i + 1];  // Ustaw œcie¿kê do pliku wyjœciowego
            i++; // Przeskocz do nastêpnego argumentu
        }
        else {
            std::cout << "Nieznany argument lub brak wartoœci: " << arg << std::endl;
            std::cout << "U¿ycie: " << argv[0] << " -i plik_wejsciowy [-o plik_wyjsciowy]" << std::endl;
            return 1;  // Zakoñcz program z kodem b³êdu
        }
    }

    // Sprawdzenie, czy podano plik wejœciowy
    if (plikWejsciowy.empty()) {
        std::cout << "B³¹d: Nie podano pliku wejœciowego!" << std::endl;
        std::cout << "U¿ycie: " << argv[0] << " -i plik_wejsciowy [-o plik_wyjsciowy]" << std::endl;
        return 1;  // Zakoñcz program z kodem b³êdu
    }

    // Inicjalizacja interpretera Brainfuck
    BrainfuckInterpreter interpreter;

    // Wczytanie programu Brainfuck z pliku
    if (!interpreter.wczytajProgram(plikWejsciowy)) {
        std::cout << "B³¹d: Nie mo¿na otworzyæ pliku " << plikWejsciowy << "!" << std::endl;
        return 1;  // Zakoñcz program z kodem b³êdu
    }

    // Wykonanie programu Brainfuck
    if (plikWyjsciowy.empty()) {
        // Wynik na standardowe wyjœcie
        interpreter.wykonajProgram(std::cout);
    }
    else {
        // Wynik do pliku wyjœciowego
        std::ofstream plikWy(plikWyjsciowy);
        if (!plikWy) {
            std::cout << "B³¹d: Nie mo¿na otworzyæ pliku wyjœciowego " << plikWyjsciowy << "!" << std::endl;
            return 1;  // Zakoñcz program z kodem b³êdu
        }
        interpreter.wykonajProgram(plikWy);
        plikWy.close();
    }

    return 0;  // Zakoñcz program z kodem sukcesu
}