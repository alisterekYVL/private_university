#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void p1() {
    const int maxSize = 100;
    double tab[maxSize];
    int n;
    do {
        cout << "n = ";
        cin >> n;
    } while (n < 1 || n > 100); 

    for (int i = 0; i < n; i++) {
        cout << "Ocena " << i + 1 << ": ";
            cin >> tab[i];
        }
    for (int i = 0; i < n;++i) {
        cout << tab[i] << endl;
    }
    double sum = 0.0;
    double min = tab[0], max = tab[0];

    for (int i = 0; i < n; ++i) {
        sum += tab[i];
        if (tab[i] > max) max = tab[i];
        if (tab[i] < min) min = tab[i];
    }
    cout << "Suma = " << sum << endl;
    cout << "Średnia = " << sum / n << endl;
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;
    cout << "Liczba Bajtow = " << sizeof(tab) << endl;
    cout << "Liczba elementów = " << sizeof(tab) / sizeof(tab[0]) << endl;
}

void p2() {
    int n;
    do {
        cout << "n = ";
        cin >> n;
    } while (n < 1);

    double* tab = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "Ocena " << i + 1 << ": ";
        cin >> tab[i];
    }
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << endl;
    }
    double sum = 0.0;
    double min = tab[0], max = tab[0];

    for (int i = 0; i < n; ++i) {
        sum += tab[i];
        if (tab[i] > max) max = tab[i];
        if (tab[i] < min) min = tab[i];
    }
    cout << "Suma = " << sum << endl;
    cout << "Średnia = " << sum / n << endl;
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;
    cout << "Liczba Bajtow = " << sizeof(tab[0] * n) << endl;
    cout << "Liczba elementow = " << n << endl;

    delete[] tab;
}

void p3() {
    int n;
    do {
        cout << "n = ";
        cin >> n;
    } while (n < 1);

    vector<double> tab(n);

    for (int i = 0; i < tab.size(); i++) {
        cout << "Ocena " << i + 1 << ": ";
        cin >> tab[i];
    }

    for (int i = 0; i < tab.size(); ++i) {
        cout << tab[i] << endl;
    }

    double sum = 0.0;
    double min = tab[0], max = tab[0];

    for (int i = 0; i < tab.size(); ++i) {
        sum += tab[i];
        if (tab[i] > max) max = tab[i];
        if (tab[i] < min) min = tab[i];
    }

    cout << "Suma = " << sum << endl;
    cout << "Średnia = " << sum / tab.size() << endl;
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;
    cout << "Liczba Bajtow = " << sizeof(tab) << endl;
    cout << "Liczba elementow = " << tab.size() << endl;

}

void p4() {

    vector<double> tab;
    int i = 1;
    while (true) {
        double x;
        cout << "Ocena " << i++ << ": ";
        cin >> x;
        if (x == 0.0) break;
        tab.push_back(x);
    }

    for (const double el : tab) {
        cout << el << endl;
    }

    double sum = 0.0;
    double min = tab[0], max = tab[0];

    for (const auto el : tab) {
        sum += el;
        if (el > max) max = el;
        if (el < min) min = el;
    }

    cout << "Suma = " << sum << endl;
    cout << "Średnia = " << sum / tab.size() << endl;
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;
    cout << "Liczba Bajtow = " << sizeof(tab) << endl;
    cout << "Liczba elementow = " << tab.size() << endl;

}

void p5() {
    const int maxSize = 100;
    double tab[maxSize][maxSize];
    int rows, cols;

    do {
        cout << "Liczba wierszy = ";
        cin >> rows;
    } while (rows < 1);

    do {
        cout << "Liczba kolumn = ";
        cin >> cols;
    } while (cols < 1);

    double sum = 0.0;
    double max = 0.0, min = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "tab[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> tab[i][j];

            sum += tab[i][j];
            if (tab[i][j] > max) max = tab[i][j];
            if (tab[i][j] < min) min = tab[i][j];
        }

    }

    double sr = sum / (rows * cols);
    cout << "Suma: " << sum << endl;
    cout << "Srednia: " << sr << endl;
    cout << "Maksymalna wartosc: " << max << endl;
    cout << "Minimalna wartosc: " << min << endl;
  
}

void p6() {
    int rows, cols;

    do {
        cout << "Liczba wierszy = ";
        cin >> rows;
    } while (rows < 1);

    do {
        cout << "Liczba kolumn = ";
        cin >> cols;
    } while (cols < 1);

    vector<vector<double>> tab(rows, vector<double>(cols));

    double sum = 0.0;
    double max = 0.0, min = 0.0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "tab[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> tab[i][j];

            sum += tab[i][j];
            if (tab[i][j] > max) max = tab[i][j];
            if (tab[i][j] < min) min = tab[i][j];
        }
    }

    for (const auto& row : tab) {
        for (const auto& el : row) {
            cout << el << "\t";
        }
        cout << endl;
    }

    double sr = sum / (rows * cols);
    cout << "Suma: " << sum << endl;
    cout << "Srednia: " << sr << endl;
    cout << "Maksymalna wartosc: " << max << endl;
    cout << "Minimalna wartosc: " << min << endl;
}

int main() {
    //p1();
    //p2();
    //p3();
    //p4();
    //p5();
    p6();

}