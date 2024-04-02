#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s;
    f >> s;
    vector<int> t, d;
    while (f >> s && s[0] != 'D') t.push_back(stoi(s));
    while (f >> s) d.push_back(stoi(s));
    for (int j = 0; j < 100000; j++) {
    for (int i = 0; i < t.size(); i++) {
        int p1 = 1;
        double 
            x1 = (t[i] - sqrt(t[i] * t[i] - 4 * d[i])) / 2,
            x2 = (t[i] + sqrt(t[i] * t[i] - 4 * d[i])) / 2;
        x1 = ceil(x1)  + (x1 == floor(x1));
        x2 = floor(x2) - (x2 == floor(x2));
        p1 *= x2 - x1 + 1;
        cout << p1;
    }
    }
}
