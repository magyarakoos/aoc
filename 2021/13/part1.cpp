#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e4;
bool m[MAXN][MAXN];
int main() {
    ifstream f("input");
    string s;
    vector<array<int, 2>> ptS;
    while (getline(f, s) && s != "") {
        auto d = s.find(',');
        ptS.push_back({stoi(s.substr(0, d)), stoi(s.substr(d + 1))});
    }
    vector<array<int, 2>> foldS;
    while (getline(f, s)) {
        foldS.push_back({s[11] == 'y', stoi(s.substr(13))});
    }
}