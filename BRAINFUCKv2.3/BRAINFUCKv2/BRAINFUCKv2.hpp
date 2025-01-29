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
     * Inicjalizuje pamiêæ i ustawia wskaznik na poczatek pamieci.
     */
    BrainfuckInterpreter();

    /**
     * @brief Wczytuje program Brainfuck.
     * Funkcja wczytuje program Brainfuck z pliku o podanej nazwie.
     *
     * @param nazwaPliku Œcie¿ka do pliku z kodem.
     * @return true Jeœli plik zosta³ pomyœlnie wczytany.
     * @return false Jeœli plik nie móg³ zostaæ otwarty.
     */
    bool wczytajProgram(const std::string& nazwaPliku);

    /**
     * @brief Wykonuje wczytany program.
     *
     * Interpretuje i wykonuje wczytany program Brainfuck.
     * Wynik jest wypisywany na podany strumieñ wyjœciowy.
     *
     * @param wyjscie Strumieñ wyjœciowy, na który zostan¹ wypisane wyniki.
     */
    void wykonajProgram(std::ostream& wyjscie = std::cout);

private:
    std::vector<unsigned char> memory;  ///< Pamiêæ programu Brainfuck.
    size_t pointer;                     ///< WskaŸnik do aktualnej komórki pamiêci.
    std::vector<char> program;          ///< Wczytany program Brainfuck.
};