#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "histogram.h"



using namespace std;

int main() {
    ap::Show(ap::Histogram("data.txt"));
    cout << "--------------------------------------------------------------------------------";
    ap::Show(ap::PairHistogram("data.txt"));
}
