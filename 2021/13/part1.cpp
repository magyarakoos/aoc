#include <bits/stdc++.h>
using namespace std;

bool m[10000][10000];
int main() {
    ifstream f("input");
    string s;
    vector<array<int, 2>> ptS;
    while (getline(f, s) && s != "") {
        auto d = s.find(',');
        ptS.push_back({stoi(s.substr(0, d)), stoi(s.substr(d + 1))});
    }
    while (getline(f, s)) {
        bool t = s[11] == 'y';
        int v = stoi(s.substr(13));
        
    }
}