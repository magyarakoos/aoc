#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;
#define x first
#define y second

int main() {
    fstream f("input");
    string s;
    vector<string> v;
    while (f >> s) {
        v.push_back(s);
        if (all_of(s.begin(), s.end(), [](char c){ return c == '.'; })) {
            v.push_back(s);
        }
    }
    for (int i = 0, j; i < v[0].size(); i++) {
        for (j = 0; j < v.size() && v[j][i] == '.'; j++);
        if (j == v.size()) {
            for (int k = 0; k < v.size(); k++) {
                v[k].insert(v[k].begin() + i, '.');
            }
            i++;
        }
    }
    vector<point> px;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == '#') px.push_back({i, j});
        }
    }
    int p1 = 0;
    for (int i = 0; i < px.size(); i++) {
        for (int j = i + 1; j < px.size(); j++) {
            p1 += abs(px[i].x - px[j].x) + abs(px[i].y - px[j].y);
        }
    }
    cout << p1;
}
