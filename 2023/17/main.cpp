#include <bits/stdc++.h>
using namespace std;
using route = array<int, 3>;

constexpr array<int, 2> dirS[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
constexpr int INF = 1e9;

vector<vector<int>> g;
int N, M;

int dijkstra() {
    vector<vector<int>> distS(N, vector<int>(M, INF));
    priority_queue<route, vector<route>, greater<route>> pq;

    distS[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [dist, x, y] = pq.top(); pq.pop();

        if (dist != distS[y][x]) continue;

        if (x == M - 1 && y == N - 1) {
            
        }

        for (auto [dx, dy] : dirS) {
            int nx = x + dx, ny = y + dy;
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
                continue;
            }
            int ndist = dist + g[ny][nx];
            if (distS[ny][nx] > ndist) {
                distS[ny][nx] = ndist;
                pq.push({ndist, nx, ny});
            }
        }
    }
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

    cout << dijkstra() << "\n";
}
