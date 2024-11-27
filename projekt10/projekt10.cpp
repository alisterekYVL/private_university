#include "projekt10.hpp"
#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <numeric>



using namespace std;

void show(const vector<double>& v) {
    for (const auto el : v) {
        cout << el << endl;
    }
    cout << endl;
}

void p1() {
    vector<double> v(5, 13.3);
    for (const auto el : v) {
        cout << el << endl;
    }

    cout << "\n";

    list<double> l;
    l.push_back(13.6);
    l.push_front(11.8);
    l.insert(l.begin(), 8.7);
    for (const auto el : l) {
        cout << el << endl;
    }

    cout << "\n";

    set<int> s;
    s.insert(12);
    s.insert(13);
    s.insert(11);
    s.insert(12);
    for (const auto el : s) {
        cout << el << endl;
    }
    cout << s.count(12) << endl;
    cout << s.count(9) << endl;

    cout << "\n";

    stack<int> st;
    st.push(11);
    st.push(17);
    st.push(21);

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    cout << "\n";

    queue<int> q;
    q.push(12);
    q.push(13);
    q.push(14);
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    cout << "\n";

    map<string, int> m;

    m["Polska"] = 48;
    m["Francja"] = 148;

    for (const auto& el : m) {
        cout << el.first << " : " << el.second << endl;
    }

    cout << "\n";



}

void p2() {
    vector<double> v = { 4,9,-3,21, 13};
    show(v);
    //sort(v.begin(), v.end());
    //reverse(v.begin(), v.end());

    sort(v.begin(), v.end(), [](const auto l, const auto r) {return l > r; });
    show(v);

    auto min = *min_element(v.begin(), v.end());
    cout << "min = " << min << endl;

    auto max = *max_element(v.begin(), v.end());
    cout << "min = " << max << endl;

    auto sum = accumulate(v.begin(), v.end(), 0.0);
    cout << "Suma = " << sum << endl;

    auto count = count_if(v.begin(), v.end(), [](const auto x) {return x > 0.0; });
    cout << "Liczba dodatnich = " << count << endl;
}

int main() {

    //p1();
    p2();
}
