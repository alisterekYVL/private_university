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
     * Inicjalizuje pamiêæ o rozmiarze 30000 bajtow (domyœlny rozmiar dla Brainfuck)
     * i ustawia wskaznik na poczatek pamieci.
     */
    BrainfuckInterpreter();

    /**
     * @brief Wczytuje program Brainfuck z pliku.
     *
     * Funkcja wczytuje program Brainfuck z pliku o podanej nazwie.
     * Ignoruje znaki, które nie s¹ czêœci¹ jêzyka Brainfuck.
     *
     * @param nazwaPliku Œcie¿ka do pliku z kodem Brainfuck.
     * @return true Jeœli plik zosta³ pomyœlnie wczytany.
     * @return false Jeœli plik nie móg³ zostaæ otwarty.
     */
    bool wczytajProgram(const std::string& nazwaPliku);

    /**
     * @brief Wykonuje wczytany program Brainfuck.
     *
     * Interpretuje i wykonuje wczytany program Brainfuck.
     * Wynik jest wypisywany na podany strumieñ wyjœciowy.
     *
     * @param wyjscie Strumieñ wyjœciowy, na który zostan¹ wypisane wyniki (domyœlnie std::cout).
     */
    void wykonajProgram(std::ostream& wyjscie = std::cout);

private:
    std::vector<unsigned char> memory;  ///< Pamiêæ programu Brainfuck (30000 bajtów).
    size_t pointer;                     ///< WskaŸnik do aktualnej komórki pamiêci.
    std::vector<char> program;          ///< Wczytany program Brainfuck.
};