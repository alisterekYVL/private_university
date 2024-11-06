#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cout << "Podaj tekst: ";
    getline(cin, s);

    int pos = s.find('A', 0);
    while (pos != string::npos) {
        s[pos] = '.';
        pos = s.find('A', pos + 1);
    }

    pos = s.find('a', 0);
    while (pos != string::npos) {
        s[pos] = '.';
        pos = s.find('a', pos + 1);
    }


    for (int i = 0; i < s.length(); ++i) {
        if (i % 2 == 0) {
            s[i] = toupper(s[i]);  
        }
        else {
            s[i] = tolower(s[i]); 
        }
    }

    cout << "Przeksztalcony tekst: " << s << endl;

}