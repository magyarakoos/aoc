#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e4;
bool m[MAXN][MAXN];

int cnt() {
    int res = 0;
    for (int y = 0; y < MAXN; y++) {
        for (int x = 0; x < MAXN; x++) {
            res += m[y][x];
        }
    }
    return res;
}

int main() {
    ifstream f("input");
    string s;
    vector<array<int, 2>> ptS;
    while (getline(f, s) && s != "") {
        auto d = s.find(',');
        m[stoi(s.substr(d + 1))][stoi(s.substr(0, d))] = 1;
    }
    for (int i = 0; getline(f, s); i++) {
        int v = stoi(s.substr(13));
        if (s[11] == 'y') {
            for (int l = 0, r = v * 2; l < r; l++, r--) {
                for (int x = 0; x < MAXN; x++) {
                    m[l][x] = m[l][x] || m[r][x];
                    m[r][x] = 0;
                }
            }
        } else {
            for (int l = 0, r = v * 2; l < r; l++, r--) {
                for (int y = 0; y < MAXN; y++) {
                    m[y][l] = m[y][l] || m[y][r];
                    m[y][r] = 0;
                }
            }
        }
        if (!i) cout << cnt() << "\n";
    //     for (int y = 0; y < 20; y++) {
    //         for (int x = 0; x < 20; x++) {
    //             cout << (m[y][x] ? "#" : ".");
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n";
    }
    cout << cnt();
}