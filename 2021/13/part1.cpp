#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s;
    vector<array<int, 2>> ptS;
    while (f >> s && s != "") {
        auto d = s.find(',');
        ptS.push_back({stoi(s.substr(0, d)), stoi(s.substr(d))});
    }
    vector<array<int, 2>> foldS;
    while (f >> s) {
        foldS.push_back({s[11] == 'y', stoi(s.substr(13))});
    }
    
    for (auto [x, y] : ptS) cout << x << " " << y << "\n";
    cout << "\n";
    for (auto [t, v] : foldS) cout <<  t << " " << v << "\n";
}