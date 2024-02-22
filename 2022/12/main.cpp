#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;
constexpr point dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    ifstream f("input");
    string s;
    vector<string> grid;
    while (f >> s) {
        grid.push_back(s);
    }

    point sp, ep;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'S') {
                sp = {i, j};
            }
            if (grid[i][j] == 'E') {
                ep = {i, j};
            }
        }
    }
    
    set<point> vis({sp});
    queue<array<int, 3>> q({{sp[0], sp[1], 0}});

    while (q.empty()) {
        auto [y, x, steps] = q.front(); q.pop();

        if (y == ep[0] && x == ep[1]) {
            cout << steps;
            exit(0);
        }

        for (point dir : dirs) {
            point np = {dir[0] + y, dir[1] + x};
            if (np[0] < 0 || np[1] < 0 || np[0] >= N || np[1] >= M) {
                continue;
            }

            if (grid[y][x] - grid[np[0]][np[1]] >= -1 && !vis.count(np)) {
                vis.insert(np);
                q.push({np[0], np[1], steps + 1});
            }
        }
    }
}