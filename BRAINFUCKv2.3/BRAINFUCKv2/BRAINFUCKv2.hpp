#include <string>
#include <vector>
#include <iostream>

/**
 * @class BrainfuckInterpreter
 * @brief Klasa interpretujaca programy Brainfuck.
 *
 * Klasa umozliwia wczytywanie i wykonywanie programow .
 * Sklada sie z pamieci, wskaznika pamieci oraz programu do wykonania.
 */
class BrainfuckInterpreter {
public:
    /**
     * @brief Konstruktor
     *
     * Inicjalizuje pami�� i ustawia wskaznik na poczatek pamieci.
     */
    BrainfuckInterpreter();

    /**
     * @brief Wczytuje program Brainfuck.
     * Funkcja wczytuje program Brainfuck z pliku o podanej nazwie.
     *
     * @param nazwaPliku �cie�ka do pliku z kodem.
     * @return true Je�li plik zosta� pomy�lnie wczytany.
     * @return false Je�li plik nie m�g� zosta� otwarty.
     */
    bool wczytajProgram(const std::string& nazwaPliku);

    /**
     * @brief Wykonuje wczytany program.
     *
     * Interpretuje i wykonuje wczytany program Brainfuck.
     * Wynik jest wypisywany na podany strumie� wyj�ciowy.
     *
     * @param wyjscie Strumie� wyj�ciowy, na kt�ry zostan� wypisane wyniki.
     */
    void wykonajProgram(std::ostream& wyjscie = std::cout);

private:
    std::vector<unsigned char> memory;  ///< Pami�� programu Brainfuck.
    size_t pointer;                     ///< Wska�nik do aktualnej kom�rki pami�ci.
    std::vector<char> program;          ///< Wczytany program Brainfuck.
};