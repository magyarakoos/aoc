#include <bits/stdc++.h>
using namespace std;

using point = array<int, 2>;
vector<string> grid;
int N, M;

void bounce(point p, point dir, vector<vector<point>>& vis) {
    point& v = vis[p[1]][p[0]];
    if (p[1] < 0 || p[1] >= N || p[0] < 0 || p[0] >= M || dir == v) return;
    if (!(v[0] + v[1])) v = dir;
    char c = grid[p[1]][p[0]];
    if (c == '-' && !dir[0]) {
        bounce({p[0] - 1, p[1]}, {-1, 0}, vis);
        bounce({p[0] + 1, p[1]}, {1, 0}, vis);
        return;
    } else if (c == '|' && !dir[1]) {
        bounce({p[0], p[1] - 1}, {0, -1}, vis);
        bounce({p[0], p[1] + 1}, {0, 1}, vis);
        return;
    } else if (c == '/') {
        dir = {-dir[1], -dir[0]};
    } else if (c == '\\') {
        swap(dir[0], dir[1]);
    }
    bounce({p[0] + dir[0], p[1] + dir[1]}, dir, vis);
}

int solve(point p, point dir) {
    vector<vector<point>> vis(N, vector<point>(M, {0, 0}));
    bounce(p, dir, vis);
    int result = 0;
    for (const auto& l : vis) for (const point& p : l) result += (bool)(p[0] + p[1]);
    return result;
}

int main() {
    fstream f("input");
    string s;
    while (f >> s) grid.push_back(s);
    N = grid.size(), M = grid[0].size();
    int p1 = solve({0, 0}, {1, 0}), p2 = p1;
    for (int i = 1; i < N; i++) {
        p2 = max({p2, solve({0, i}, {1, 0}), solve({M - 1, i}, {-1, 0})});
    }
    for (int i = 0; i < M; i++) {
        p2 = max({p2, solve({i, 0}, {0, 1}), solve({i, N - 1}, {0, -1})});
    }
    cout << p1 << '\n' << p2;
}
