#include <iostream>

int main()
{
    float x, y;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;
    float z = x > y ? x : y;
    std::cout << "maks = " << (x > y ? x : y) << std::endl;
}