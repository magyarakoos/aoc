#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s;
    f >> s;
    vector<int> t({0}), d({0});
    while (f >> s && s[0] != 'D') t.push_back(stoi(s));
    while (f >> s) d.push_back(stoi(s));
    int p1 = 1;
    for (int i = 0; i < t.size(); i++) {
        double x1 = (-t[i] - sqrt(t[i]*t[i]-4*d[i])) / 2;
        double x2 = (-t[i] + sqrt(t[i]*t[i]-4*d[i])) / 2;
    }
    cout << p1;
}
