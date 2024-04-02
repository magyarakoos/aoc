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
        float x1 = 
    }
    cout << p1;
}
