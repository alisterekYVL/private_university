#include "BRAINFUCKv2.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>


BrainfuckInterpreter::BrainfuckInterpreter() : memory(30000, 0), pointer(0) {}

bool BrainfuckInterpreter::wczytajProgram(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik) {
        return false; 
    }
    char znak;
    while (plik.get(znak)) {
        if (znak == '+' || znak == '-' || znak == '<' || znak == '>' ||
            znak == '[' || znak == ']' || znak == '.' || znak == ',') {
            program.push_back(znak);
        }
    }
    plik.close();
    return true; 
}


void BrainfuckInterpreter::wykonajProgram(std::ostream& wyjscie) {
    size_t ip = 0; 
    std::vector<size_t> stos; 

    while (ip < program.size()) {
        switch (program[ip]) {
        case '>':
            pointer = (pointer + 1) % memory.size();
            break;
        case '<':
            pointer = (pointer - 1 + memory.size()) % memory.size();
            break;
        case '+':
            memory[pointer] = (memory[pointer] + 1) % 256; 
            break;
        case '-':
            memory[pointer] = (memory[pointer] - 1 + 256) % 256; 
            break;
        case '.':
            wyjscie.put(static_cast<char>(memory[pointer]));
            break;
        case ',': {
            char znak;
            if (std::cin.get(znak)) {
                memory[pointer] = static_cast<unsigned char>(znak);
            }
            else {
                memory[pointer] = 0;
            }
            break;
        }
        case '[':
            if (memory[pointer] == 0) {
                int petle = 1;
                while (petle > 0 && ip < program.size()) {
                    ip++;
                    if (program[ip] == '[') petle++;
                    if (program[ip] == ']') petle--;
                }
            }
            else {
                stos.push_back(ip);
            }
            break;
        case ']':
            if (stos.empty()) {
                throw std::runtime_error("Nieprawidłowa struktura programu: brak odpowiadającego '['");
            }
            if (memory[pointer] != 0) {
                ip = stos.back() - 1; 
            }
            else {
                stos.pop_back();
            }
            break;
        }
        ip++;
    }
}