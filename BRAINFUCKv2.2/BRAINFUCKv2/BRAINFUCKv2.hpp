#include <string>
#include <vector>
#include <iostream>

/**
 * @class BrainfuckInterpreter
 * @brief Klasa interpretujaca programy napisane w jezyku Brainfuck.
 *
 * Klasa umozliwia wczytywanie i wykonywanie programow Brainfuck.
 * Sklada sie z pamieci o rozmiarze 30000 bajtow, wskaznika pamieci oraz programu do wykonania.
 */
class BrainfuckInterpreter {
public:
    /**
     * @brief Konstruktor
     *
     * Inicjalizuje pami�� o rozmiarze 30000 bajtow (domy�lny rozmiar dla Brainfuck)
     * i ustawia wskaznik na poczatek pamieci.
     */
    BrainfuckInterpreter();

    /**
     * @brief Wczytuje program Brainfuck z pliku.
     *
     * Funkcja wczytuje program Brainfuck z pliku o podanej nazwie.
     * Ignoruje znaki, kt�re nie s� cz�ci� j�zyka Brainfuck.
     *
     * @param nazwaPliku �cie�ka do pliku z kodem Brainfuck.
     * @return true Je�li plik zosta� pomy�lnie wczytany.
     * @return false Je�li plik nie m�g� zosta� otwarty.
     */
    bool wczytajProgram(const std::string& nazwaPliku);

    /**
     * @brief Wykonuje wczytany program Brainfuck.
     *
     * Interpretuje i wykonuje wczytany program Brainfuck.
     * Wynik jest wypisywany na podany strumie� wyj�ciowy.
     *
     * @param wyjscie Strumie� wyj�ciowy, na kt�ry zostan� wypisane wyniki (domy�lnie std::cout).
     */
    void wykonajProgram(std::ostream& wyjscie = std::cout);

private:
    std::vector<unsigned char> memory;  ///< Pami�� programu Brainfuck (30000 bajt�w).
    size_t pointer;                     ///< Wska�nik do aktualnej kom�rki pami�ci.
    std::vector<char> program;          ///< Wczytany program Brainfuck.
};