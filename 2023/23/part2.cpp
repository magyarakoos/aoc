#include <bits/stdc++.h>
using namespace std;

map<array<int, 2>, vector<array<int, 3>>> g;
vector<vector<bool>> vis;
int n, result;

void read() {
    vector<vector<int>> grid;
    string line;
    while (getline(cin, line)) {
        grid.push_back({});
        for (char c : line) {
            grid.back().push_back(c == '#');
        }
    }
    int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
    n = grid.size();
    vis.assign(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni >= 0 && nj >= 0 && ni < n &&
                    nj < n && !grid[ni][nj]) {
                    g[{i, j}].push_back({ni, nj, 1});
                }
            }
        }
    }
}

void compress() {
    for (bool ok = 1; ok;) {
        ok = 0;
        for (auto it = g.begin(); it != g.end();) {
            const auto& [node, edges] = *it;
            if (edges.size() == 2) {
                const auto &e1 = edges[0], &e2 = edges[1];
                array<int, 2> n1{e1[0], e1[1]},
                    n2{e2[0], e2[1]};
                int w = e1[2] + e2[2];
                g[n1].push_back({n2[0], n2[1], w});
                g[n2].push_back({n1[0], n1[1], w});
                for (auto& n : {n1, n2})
                    g[n].erase(
                        remove_if(g[n].begin(), g[n].end(),
                                  [&node](const auto& e) {
                                      return e[0] ==
                                                 node[0] &&
                                             e[1] ==
                                                 node[1];
                                  }),
                        g[n].end());
                it = g.erase(it);
                ok = 1;
            } else
                ++it;
        }
    }
}

void dfs(int i, int j, int d) {
    if (i == n - 1 && j == n - 2) {
        result = max(result, d);
    } else if (!vis[i][j]) {
        vis[i][j] = 1;
        for (auto [k, l, w] : g[{i, j}]) {
            dfs(k, l, d + w);
        }
        vis[i][j] = 0;
    }
}

int main() {
    read();
    compress();
    dfs(0, 1, 0);
    cout << result;
}
