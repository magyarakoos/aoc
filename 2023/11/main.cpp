#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;
#define x first
#define y second

int main() {
    fstream f("input");
    string s;
    vector<string> v;
    vector<int> gapsX, gapsY;
    while (f >> s) {
        v.push_back(s);
        if (all_of(s.begin(), s.end(), [](char c){ return c == '.'; })) {
            gapsX.push_back(v.size() - 1);
        }
    }
    for (int i = 0, j; i < v[0].size(); i++) {
        for (j = 0; j < v.size() && v[j][i] == '.'; j++);
        if (j == v.size()) gapsY.push_back(i);
    }
    vector<point> px;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == '#') px.push_back({i, j});
        }
    }
    long long p1 = 0, p2 = 0;
    for (int i = 0; i < px.size(); i++) {
        for (int j = i + 1; j < px.size(); j++) {
            long long n = 0, dist = abs(px[i].x - px[j].x) + abs(px[i].y - px[j].y);
            for (int g : gapsX) {
                if (min(px[i].x, px[j].x) < g && max(px[i].x, px[j].x) > g) {
                    n++;
                }
            }
            for (int g : gapsY) {
                if (min(px[i].y, px[j].y) < g && max(px[i].y, px[j].y) > g) {
                    n++;
                }
            }
            p1 += dist + n;
            p2 += abs(px[i].x - px[j].x) + abs(px[i].y - px[j].y) + n * (1e6 - 1);
        }
    }
    cout << p1 << '\n' << p2;
}
