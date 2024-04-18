#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s;
    vector<array<int, 2>> ptS;
    while (f >> s && s != "") {
        auto d = s.find(',');
        ptS.push_back({stoi(s.substr(0, d))})
    }
}