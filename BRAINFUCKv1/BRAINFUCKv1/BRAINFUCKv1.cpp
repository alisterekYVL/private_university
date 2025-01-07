#include "BRAINFUCK.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <stack>
#include <stdexcept>

namespace ap {

    namespace {
        // Struktura przechowująca stan interpretera
        struct StanInterpretera {
            std::vector<unsigned char> pamiec;
            std::size_t wskaznikPamieci;
            std::stack<std::size_t> stosPetli;
        };

        // Inicjalizacja stanu interpretera
        StanInterpretera inicjalizujStan() {
            return StanInterpretera{ {std::vector<unsigned char>(30000, 0)}, 0, {} };
        }

        // Funkcja wykonująca kod Brainfuck
        void wykonajKod(StanInterpretera& stan, const std::string& kod, std::ostream& wyjscie) {
            std::size_t wskaznikInstrukcji = 0;

            while (wskaznikInstrukcji < kod.size()) {
                char komenda = kod[wskaznikInstrukcji];
                switch (komenda) {
                case '>':
                    ++stan.wskaznikPamieci;
                    if (stan.wskaznikPamieci >= stan.pamiec.size()) {
                        throw std::runtime_error("Przekroczenie pamieci.");
                    }
                    break;
                case '<':
                    if (stan.wskaznikPamieci == 0) {
                        throw std::runtime_error("Przekroczenie poczatku pamieci.");
                    }
                    --stan.wskaznikPamieci;
                    break;
                case '+':
                    ++stan.pamiec[stan.wskaznikPamieci];
                    break;
                case '-':
                    --stan.pamiec[stan.wskaznikPamieci];
                    break;
                case '.':
                    wyjscie.put(stan.pamiec[stan.wskaznikPamieci]);
                    break;
                case ',':
                    stan.pamiec[stan.wskaznikPamieci] = std::cin.get();
                    break;
                case '[':
                    // Jeśli komórka pamięci jest 0, to skaczemy do pozycji za zamknięciem ']'
                    if (stan.pamiec[stan.wskaznikPamieci] == 0) {
                        int licznikPetli = 1;
                        while (licznikPetli > 0 && ++wskaznikInstrukcji < kod.size()) {
                            if (kod[wskaznikInstrukcji] == '[') licznikPetli++;
                            else if (kod[wskaznikInstrukcji] == ']') licznikPetli--;
                        }
                    }
                    else {
                        stan.stosPetli.push(wskaznikInstrukcji);
                    }
                    break;
                case ']':
                    if (stan.stosPetli.empty()) {
                        throw std::runtime_error("Niezbalansowane nawiasy [].");
                    }
                    if (stan.pamiec[stan.wskaznikPamieci] != 0) {
                        // Powrócimy do początku pętli
                        wskaznikInstrukcji = stan.stosPetli.top();
                    }
                    else {
                        stan.stosPetli.pop();
                    }
                    break;
                }
                ++wskaznikInstrukcji;
            }
        }
    } // namespace

    // Funkcja do wczytania kodu z pliku
    std::string wczytajPlik(const std::string& nazwaPliku) {
        std::ifstream plik(nazwaPliku);
        if (!plik.is_open()) {
            std::cerr << "Nie mozna otworzyc pliku: " << nazwaPliku << std::endl;
            return ""; // Zwracamy pusty ciąg, gdy plik nie został otwarty
        }
        return std::string((std::istreambuf_iterator<char>(plik)), std::istreambuf_iterator<char>());
    }

    // Funkcja wykonująca kod Brainfuck
    void wykonajBrainfuck(const std::string& kod, std::ostream& wyjscie) {
        auto stan = inicjalizujStan();
        wykonajKod(stan, kod, wyjscie);
    }

} // namespace ap

int main() {
    try {
        // Wczytanie kodu Brainfuck z pliku "kod.txt"
        std::string kod = ap::wczytajPlik("kod.txt");

        // Jeśli kod jest pusty, zakończ działanie programu
        if (kod.empty()) {
            std::cerr << "Błąd: Nie udało się wczytać kodu z pliku!" << std::endl;
            return 1; // Zakończenie programu z kodem błędu
        }

        // Wykonanie kodu Brainfuck i wypisanie wyników na standardowe wyjście
        ap::wykonajBrainfuck(kod, std::cout);
    }
    catch (const std::exception& e) {
        // Obsługa wyjątków, np. błędy interpretacji kodu Brainfuck
        std::cerr << "Błąd: " << e.what() << std::endl;
    }

    return 0;
}
