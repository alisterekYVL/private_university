#include <iostream>
#include <string>

using namespace std;
int main() {
	string s = " ala ma kota "; //string s("ala ma kota ");
	cout << s << endl;

	string s1;
	cout << s1 << endl;
	cout << "Wprowadz napis: ";
	cin >> s1;
	cout << s1;

	cout << s + s1 << endl;

	for (int i = 0; i < s.length(); ++i) {
		cout << s[i];
	}
	cout << endl;

	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << *it;
	}
	cout << endl;

	for (const auto el : s) {
		cout << el;
	}
	cout << endl;

	if (s == "ala ma kota") {
		for (auto& el : s) {
			el = toupper(el);
		}
	}
	else {
		for (auto& el : s) {
			el = tolower(el); 
		}
	}
	cout << s << endl;

} 


