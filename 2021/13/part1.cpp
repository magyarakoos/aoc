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
    while (getline(f, s)) {
        int v = stoi(s.substr(13));
        if (s[11] == 'y') {
            for (int l = 0, r = v * 2; l < r; l++, r--) {
                for (int x = 0; x < MAXN; x++) {
                    
                }
            }
        } else {

        }
    }
}