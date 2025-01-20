#include "BRAINFUCKv2.hpp"
#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief G��wna funkcja programu.
 *
 * Program interpretuje kod Brainfuck wczytany z pliku wej�ciowego i wypisuje wynik na standardowe wyj�cie lub do pliku wyj�ciowego.
 *
 * @param argc Liczba argument�w przekazanych do programu.
 * @param argv Tablica argument�w przekazanych do programu.
 * @return int Kod zako�czenia programu (0 w przypadku sukcesu, 1 w przypadku b��du).
 */
int main(int argc, char* argv[]) {
    std::string plikWejsciowy;  // �cie�ka do pliku wej�ciowego z kodem Brainfuck
    std::string plikWyjsciowy;  // �cie�ka do pliku wyj�ciowego (opcjonalnie)

    // R�czne parsowanie argument�w linii polece�
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-i" && i + 1 < argc) {
            plikWejsciowy = argv[i + 1];  // Ustaw �cie�k� do pliku wej�ciowego
            i++; // Przeskocz do nast�pnego argumentu
        }
        else if (arg == "-o" && i + 1 < argc) {
            plikWyjsciowy = argv[i + 1];  // Ustaw �cie�k� do pliku wyj�ciowego
            i++; // Przeskocz do nast�pnego argumentu
        }
        else {
            std::cout << "Nieznany argument lub brak warto�ci: " << arg << std::endl;
            std::cout << "U�ycie: " << argv[0] << " -i plik_wejsciowy [-o plik_wyjsciowy]" << std::endl;
            return 1;  // Zako�cz program z kodem b��du
        }
    }

    // Sprawdzenie, czy podano plik wej�ciowy
    if (plikWejsciowy.empty()) {
        std::cout << "B��d: Nie podano pliku wej�ciowego!" << std::endl;
        std::cout << "U�ycie: " << argv[0] << " -i plik_wejsciowy [-o plik_wyjsciowy]" << std::endl;
        return 1;  // Zako�cz program z kodem b��du
    }

    // Inicjalizacja interpretera Brainfuck
    BrainfuckInterpreter interpreter;

    // Wczytanie programu Brainfuck z pliku
    if (!interpreter.wczytajProgram(plikWejsciowy)) {
        std::cout << "B��d: Nie mo�na otworzy� pliku " << plikWejsciowy << "!" << std::endl;
        return 1;  // Zako�cz program z kodem b��du
    }

    // Wykonanie programu Brainfuck
    if (plikWyjsciowy.empty()) {
        // Wynik na standardowe wyj�cie
        interpreter.wykonajProgram(std::cout);
    }
    else {
        // Wynik do pliku wyj�ciowego
        std::ofstream plikWy(plikWyjsciowy);
        if (!plikWy) {
            std::cout << "B��d: Nie mo�na otworzy� pliku wyj�ciowego " << plikWyjsciowy << "!" << std::endl;
            return 1;  // Zako�cz program z kodem b��du
        }
        interpreter.wykonajProgram(plikWy);
        plikWy.close();
    }

    return 0;  // Zako�cz program z kodem sukcesu
}