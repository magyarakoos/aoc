#include <bits/stdc++.h>
using namespace std;
array<int, 2> dirS[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

vector<vector<int>> g;
int N, M;

int dijkstra(int min_step, int max_step) {
    vector<vector<vector<vector<int>>>> distS(N, vector<vector<vector<int>>>(M, vector<vector<int>>(4, vector<int>(max_step + 1, INT_MAX))));
    priority_queue<array<int, 5>, vector<array<int, 5>>, greater<array<int, 5>>> pq;

    distS[0][0][0][0] = 0;
    pq.push({0, 0, 0, -1, 0});

    while (!pq.empty()) {
        auto [dist, x, y, dir, step] = pq.top(); pq.pop();

        if (dir != -1 && dist != distS[x][y][dir][step]) continue;

        if (x == M - 1 && y == N - 1 && step >= min_step) {
            return distS[x][y][dir][step];
        }

        for (int i = 0; i < 4; i++) {
            auto [dx, dy] = dirS[i];
            int nx = x + dx, ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= M || ny >= N ||
                dir == (i + 2) % 4 || (
                (i != dir && step <  min_step) ||
                (i == dir && step >= max_step)
                ) && dir != -1) continue;

            int nstep = (i == dir ? step + 1 : 1);
            int ndist = dist + g[ny][nx];

            if (distS[nx][ny][i][nstep] > ndist) {
                distS[nx][ny][i][nstep] = ndist;
                pq.push({ndist, nx, ny, i, nstep});
            }
        }
    }

    return -1;
}

int main() {
    ifstream f("input");
    string s;

    while (f >> s) {
        vector<int> v;
        for (char c : s) {
            v.push_back(c - '0');
        }
        g.push_back(v);
    }

    N = g.size(), M = g[0].size();

    cout << dijkstra(1, 3) << "\n" << dijkstra(4, 10);
}
