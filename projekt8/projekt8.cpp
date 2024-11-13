#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void swap(double& x, double& y) {
    float buffer = x;
    x = y;
    y = buffer;
}

int main() {
    float a = 13;
    float b = 17;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "\n";

    swap(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "\n";

}

