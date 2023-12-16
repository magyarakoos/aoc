#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;
#define x first
#define y second

vector<string> grid;
int N, M;

void bounce(point p, point dir, vector<vector<pair<bool, point>>>& vis) {
    auto& v = vis[p.y][p.x];
    if (p.y < 0 || p.y >= N || p.x < 0 || p.x >= M || (v.x && dir == v.y)) return;
    if (!v.x) v.y = dir;
    v.x = 1;
    char c = grid[p.y][p.x];
    if (c == '-' && !dir.x) {
        bounce({p.x - 1, p.y}, {-1, 0}, vis);
        bounce({p.x + 1, p.y}, {1, 0}, vis);
        return;
    } else if (c == '|' && !dir.y) {
        bounce({p.x, p.y - 1}, {0, -1}, vis);
        bounce({p.x, p.y + 1}, {0, 1}, vis);
        return;
    } else if (c == '/') {
        dir = {-dir.y, -dir.x};
    } else if (c == '\\') {
        dir = {dir.y, dir.x};
    }
    bounce({p.x + dir.x, p.y + dir.y}, dir, vis);
}

int solve(point p, point dir) {
    vector<vector<pair<bool, point>>> vis(N, vector<pair<bool, point>>(M));
    bounce(p, dir, vis);
    int result = 0;
    for (const auto& l : vis) for (auto& b : l) result += b.x;
    return result;
}

int main() {
    fstream f("input");
    string s;
    while (f >> s) {
        grid.push_back(s);
    }
    N = grid.size();
    M = grid[0].size();
    int p1 = solve({0, 0}, {1, 0}), p2 = p1;
    for (int i = 1; i < N; i++) {
        p2 = max(p2, solve({0, i}, {1, 0}));
        p2 = max(p2, solve({M - 1, i}, {-1, 0}));
    }
    for (int i = 0; i < M; i++) {
        p2 = max(p2, solve({i, 0}, {0, 1}));
        p2 = max(p2, solve({i, N - 1}, {0, -1}));
    }
    cout << p1 << '\n' << p2;
}
