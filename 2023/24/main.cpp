#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using point = array<ld, 2>;
using line = struct { ld x; ld y; ld vx; ld vy; };
const ld SUP = 2e14, INF = 4e14;

point intersect(const line& l1, const line& l2) {
    if (l1.x == l2.x && l1.y == l2.y) {
        return {l1.x, l1.y};
    }
    if (l1.vy / l1.vx == l2.vy / l2.vx) {
        return {0, 0};
    }
    ld X = 
        (l2.y * l1.vx * l2.vx - l1.vx * l2.vy * l2.x - l1.y * l2.vx * l1.vx + l2.vx * l1.vy * l1.x) / 
        (l1.vy * l2.vx - l1.vx * l2.vy);
    return {
        X,
        l1.vy / l1.vx * X + l1.y - l1.vy * l1.x / l1.vx
    };
}

int main() {
    fstream f("input");
    string s;
    vector<line> lines;
    while (getline(f, s)) {
        replace(s.begin(), s.end(), ',', ' ');
        stringstream ss(s);
        vector<string> tokens;
        while (ss >> s) {
            tokens.push_back(s);
        }
        lines.push_back({
            stold(tokens[0]), stold(tokens[1]),
            stold(tokens[4]), stold(tokens[5])
        });
    }
    int N = lines.size(), p1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            point p = intersect(lines[i], lines[j]);
            if (!(p[0] < SUP || p[1] < SUP || p[0] > INF || p[1] > INF || 
                (lines[i].vx > 0 && p[0] < lines[i].x) ||
                (lines[j].vx > 0 && p[0] < lines[j].x) ||
                (lines[i].vy > 0 && p[1] < lines[i].y) ||
                (lines[j].vy > 0 && p[1] < lines[j].y) ||
                (lines[i].vx < 0 && p[0] > lines[i].x) ||
                (lines[j].vx < 0 && p[0] > lines[j].x) ||
                (lines[i].vy < 0 && p[1] > lines[i].y) ||
                (lines[j].vy < 0 && p[1] > lines[j].y)
            )) p1++;
        }
    }
    cout << p1;
}
