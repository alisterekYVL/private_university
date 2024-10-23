#include <iostream>

void z1(){
    std::cout << "Hello\nWorld!\n";
    float x, y;
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;

    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x + y << std::endl;
    if (y != 0) {
        std::cout << "x / y = " << x / y << std::endl;
        int a = x / y;
        std::cout << "reszta z dzielenia x / y = " << a % 2 << std::endl;
    }
    else {
        std::cout << "NIE DZIEL PRZEZ 0";
    }

    void z2();{
     int m;
     std::cout << "m = ";
         std::cin >> m;
     switch (m) {
     case 1: std::cout << 31 << std::endl; break;
     case 2: std::cout << 28 << std::endl; break;
     default:
         std::cout << "Bledne dane" << std::endl; 
     }
    }



int main(); {
    //z1();
    z2();
}