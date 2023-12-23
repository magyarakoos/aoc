#include <bits/stdc++.h>
using namespace std;

using point = array<int, 2>;

vector<string> grid;
int N, M, p1;

void hike(point p, point bef, vector<vector<bool>> vis, vector<vector<int>> distS) {
    if (p[0] < 0 || p[1] < 0 || p[0] >= N || p[1] >= M) return;

    char c = grid[p[0]][p[1]];

    if (c == '#') return;

    distS[p[0]][p[1]] = (bef[0] || bef[1]) * (distS[bef[0]][bef[1]] + 1); 

    if (p[0] == N - 1 && p[1] == M - 2) {
        p1 = max(p1, distS[N - 1][M - 2]);
        return;
    }

    if (vis[p[0]][p[1]]) return;
    vis[p[0]][p[1]] = 1;

    if (c == '.') {
        hike({p[0] + 1, p[1]}, p, vis, distS);
        hike({p[0] - 1, p[1]}, p, vis, distS);
        hike({p[0], p[1] + 1}, p, vis, distS);
        hike({p[0], p[1] - 1}, p, vis, distS);
    }

    if (c == '>') {
        hike({p[0], p[1] + 1}, p, vis, distS);
    }

    if (c == 'v') {
        hike({p[0] + 1, p[1]}, p, vis, distS);
    }
}

int main() {
    fstream f("input");
    string s;
    while (f >> s) grid.push_back(s);

    N = grid.size(), M = s.size();

    hike({0, 1}, {0, 0}, vector<vector<bool>>(N, vector<bool>(M)), vector<vector<int>>(N, vector<int>(M)));

    cout << p1;
}
