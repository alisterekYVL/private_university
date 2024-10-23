#include <iostream>
#include <cmath>

using namespace std;

void p1()
{
    float sum = 0.0;
    int x = 0;
    float d;
    while (true) {
        cout << "Podaj liczbe (0 aby zakonczyc): ";
        cin >> d;
        if (d == 0) {
            break;
        }
        sum = sum + d;
        x++;
    }
    if (x > 0) {
        cout << "Suma = " << sum << endl;
        cout << "Srednia = " << sum / x << endl;
    }
    else {
        cout << "Nie wprowadzono zadnych liczb." << endl;
    }
}
int main() {
    p1();
}
