#include <iostream>
#include "int.h"
#include "corecrt_math_defines.h"
#include <vector>

double Add(const double x, const double y) { return x + y; }
double Sub(const double x, const double y) { return x - y; }
double Mul(const double x, const double y) { return x * y; }
double Div(const double x, const double y) { return x / y; }

int main() {
    std::cout <<"I sin = " << ap::Integration1(sin, 0.0, 2 * M_PI, 1000) << std::endl;
    std::cout << "I sin = " << ap::Integration2(sin, 0.0, 2 * M_PI, 1000) << std::endl;
    std::cout << "I sin = " << ap::Integration3([](const double x) {return sin(x); }, 0.0, 2 * M_PI, 1000) << std::endl;

    double(*v[])(const double, const double) = { Add, Sub, Mul, Div };
    for (int i = 0; i < sizeof(v)/sizeof(v[0]); ++i) {
        std::cout << v[i](1.0, 2.0) << std::endl;
        }

    std::vector<double(*)(const double, const double)> w = { Add, Sub, Mul, Div };
    for (const auto& el : w) {
        std::cout << el(1.0, 2.0) << std::endl;
    }
}
