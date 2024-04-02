#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    vector<int> t, d;
    string s;
    int n;
    f >> s;
    while ((f >> s) && s[0] != 'D') {
        t.push_back(stoi(s));
    }
    while (f >> n) {
        d.push_back(n);
    }
    int p1 = 1;
    for (int i = 0; i < t.size(); i++) {
        int ways = 0;
        for (int j = 1; j < t[i]; j++) {
            if (j * (t[i] - j) > d[i]) ways++;
        }
        p1 *= ways;
    }
    cout << p1;
}