#include "BRAINFUCKv2.hpp"
#include <fstream>

/**
 * @brief Klasa BrainfuckInterpreter.
 *
 * Inicjalizuje pamięć o rozmiarze 30000 bajtów  i ustawia wskaźnik na początek pamięci.
 */
BrainfuckInterpreter::BrainfuckInterpreter() : memory(30000, 0), pointer(0) {}

/**
 * @brief Wczytuje program Brainfuck z pliku.
 *
 * Funkcja wczytuje program Brainfuck z pliku o podanej nazwie.
 *
 * @param nazwaPliku Ścieżka do pliku z kodem Brainfuck.
 * @return true Jeśli plik został pomyślnie wczytany.
 * @return false Jeśli plik nie mógł zostać otwarty.
 */
bool BrainfuckInterpreter::wczytajProgram(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik) {
        return false;  // Nie można otworzyć pliku
    }
    char znak;
    while (plik.get(znak)) {
        // Filtruj tylko znaki Brainfuck
        if (znak == '+' || znak == '-' || znak == '<' || znak == '>' ||
            znak == '[' || znak == ']' || znak == '.' || znak == ',') {
            program.push_back(znak);  // Dodaj znak do programu
        }
    }
    plik.close();
    return true;
}

/**
 * @brief Wykonuje program Brainfuck.
 *
 * Interpretuje i wykonuje wczytany program Brainfuck.
 *
 * @param wyjscie Strumień wyjściowy, na który zostaną wypisane wyniki.
 */
void BrainfuckInterpreter::wykonajProgram(std::ostream& wyjscie) {
    int ip = 0;  // Instrukcja wskaźnika
    std::vector<int> stos;  // Obsługa pętli
    bool error = false; 

    // Główna pętla 
    while (ip < program.size()) {
        switch (program[ip]) {
        case '>':
            // Przesuń wskaźnik w prawo
            pointer = (pointer + 1) % memory.size();
            break;
        case '<':
            // Przesuń wskaźnik w lewo
            pointer = (pointer - 1 + memory.size()) % memory.size();
            break;
        case '+':
            // Zwiększ wartość w bieżącej komórce pamięci
            memory[pointer] = (memory[pointer] + 1) % 256;
            break;
        case '-':
            // Zmniejsz wartość w bieżącej komórce pamięci
            memory[pointer] = (memory[pointer] - 1 + 256) % 256;
            break;
        case '.':
            // Wypisz wartość bieżącej komórki jako znak
            wyjscie.put(static_cast<char>(memory[pointer]));
            break;
        case ',': {
            // Wczytaj znak z wejścia do bieżącej komórki pamięci
            char znak;
            if (std::cin.get(znak)) {
                memory[pointer] = static_cast<unsigned char>(znak);
            }
            else {
                memory[pointer] = 0;  // W przypadku błędu ustawia 0
            }
            break;
        }
        case '[':
            // Początek pętli
            if (memory[pointer] == 0) {
                // Jeśli wartość bieżącej komórki to 0, przeskocz do końca pętli
                int petle = 1;
                while (petle > 0 && ip < program.size()) {
                    ip++;
                    if (program[ip] == '[') petle++;  // Zagnieżdżona pętla
                    if (program[ip] == ']') petle--;  // Koniec pętli
                }
            }
            else {
                stos.push_back(ip);
            }
            break;
        case ']':
            if (stos.empty()) {
                error = true;
            }
            if (memory[pointer] != 0) {
                ip = stos.back() - 1;
            }
            else {
                stos.pop_back();
            }
            break;
        }
        ip++;  // Przejdź do następnej instrukcji
    }
}