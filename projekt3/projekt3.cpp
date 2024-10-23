#include <iostream>
#include <cmath>

using namespace std;

void p4() {
	int n;
	do {
		cout << "Podaj liczbe ocen = ";
			cin >> n;
	} while (n <= 0);
	float sum = 0.0;
		for (int i = 0 ;i < n; i++) {
			float d;
			cout << "Ocena " << i + 1 << ": \n";
			cin >> d;
			sum = sum + d;
	}
		cout << "Suma = " << sum << endl;
		cout << "Srednia = " << sum / n << endl;
}

void p2() {
	for (int i = -10; i < 11; i++) {
		if (i == 0) continue;
		cout << 100 / i << endl;
	}
}

void p3() {
	int x = 6;
	cout << ++x << endl;  
	cout << x << endl;

	int y = 6;
	cout << y++ << endl; 
	cout << y << endl;

	int z1 = ++x; //x = x + 1; z1 = x + 1; 
	int z2 = x++; //z2 = x; x = x + 1;
}

void p1() {
	//analogiczny (srednia i suma liczb dodatnie i ujemne) (przerwanie wprowadzania ocen gdy użytkownik wpisze 0)
	float sum = 0.0;
	int x = 0
	float = d;
	

	int main(); {
	p1(); //Zmiana tylko cyfry 
	}
