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

    int N = grid.size(), M = grid[0].size();

    point sp, ep;
    
    for (int i = 0, k = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'S') {
                sp = {i, j};
                grid[i][j] = 'a';
                k++;
            }
            else if (grid[i][j] == 'E') {
                ep = {i, j};
                grid[i][j] == 'z';
                k++;
            }
            if (k == 2) break;
        }
    }

    set<point> vis({sp});
    queue<pair<point, int>> q({{sp, 0}});

    while (!q.empty()) {
        auto [p, dist] = q.front();
        q.pop();

        if ()

        for (auto dir : dirs) {
            point np {p[0] + dir[0], p[1] + dir[1]};

            if (np[0] < 0 || np[1] < 0 || np[0] >= N || np[1] >= M || 
                vis.find(np) != vis.end() || grid[p[0]][p[1]] + 1 < grid[np[0]][np[1]]) continue;

            vis.insert(np);
            q.push({np, dist + 1});
        }
    }
}