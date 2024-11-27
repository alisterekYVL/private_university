#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;
using Vector = std::vector<double>;
using Matrix = std::vector<std::vector<double>>;

void Show(const Vector& v) {
    for (const auto el : v) {
        cout << el << endl;
    }
}

void ShowMatrix(const Matrix& m) {
    for (const auto& row : m) {
        for (const auto& el : row) {
            cout << el << " ";
        }
        cout << endl;
    }
}

bool SaveVectorToFile(const string& fileName, const Vector& v) {
    ofstream out(fileName);
    if (out) {
        for (const auto el : v) {
            out<< el << endl;
        }
        out.close();
        return true;
    }
    return false;
}

bool SaveMatrixToFile(const string& fileName, const Matrix& m) {
    ofstream out2(fileName);
    if (out2) {
        for (const auto& row : m) {
            for (const auto& el : row) {
                out2 << el << "\t";
            }
            out2 << endl;
        }
        out2.close();
        return true;
    }
    return false;
}

Vector LoadVectorFromFile(const string& fileName) {
    Vector v;
    ifstream in(fileName);
    if (in) {
        double x;
        while(in >> x) {
            v.push_back(x);
        }
        in.close();
    }
    return v;
}

Matrix LoadMatrixFromFile(const string& fileName) {
    Matrix m;
    ifstream in(fileName);
    if (in) {
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
    return m;
}

void p1() {
    vector<double> v = { 1,4,7,-14,-1,55 };
    Show(v);
    SaveVectorToFile("vector.txt", v);
}

void p2() {
    auto v = LoadVectorFromFile("vector.txt");
    Show(v);
}

void p3() {
    auto m = LoadMatrixFromFile("vector.txt");
    ShowMatrix(m);
}

int main() {
    p3();
}
