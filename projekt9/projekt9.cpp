#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getSize() {
    int n;
    do {
        cout << "n = ";
        cin >> n;
    } while (n < 1);
    return n;
}

vector<double> createVector(int n) {
    return vector<double>(n);
}

void readVector(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "Ocena " << i + 1 << ": ";
        cin >> v[i];
    }
}

void showVector(const vector<double>& v) {
    for (const auto& el : v) {
        cout << el << endl;
    }
}

double calculateSum(const vector<double>& v) {
    double sum = 0.0;
    for (double val : v) {
        sum += val;
    }
}

double findMin(const vector<double>& v) {
    double min = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < min) min = v[i];
    }
}

double findMax(const vector<double>& v) {
    double max = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > max) max = v[i];
    }
}


int main() {
    int n = getSize();  
    auto tab = createVector(n);
    readVector(tab);
    showVector(tab);  

    double sum = calculateSum(tab);
    double min = findMin(tab);
    double max = findMax(tab);

    cout << "Suma = " << sum << endl;
    cout << "Średnia = " << sum / tab.size() << endl;
    cout << "Maximum = " << max << endl;
    cout << "Minimum = " << min << endl;
    cout << "Liczba Bajtow = " << tab.size() * sizeof(double) << endl;
    cout << "Liczba elementow = " << tab.size() << endl;

    return 0;
}

