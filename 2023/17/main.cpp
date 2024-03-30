#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;
using route = array<int, 5>;

point dirS[] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

vector<vector<int>> g;
int N, M;

int dijkstra(int min_step, int max_step) {
    vector<vector<array<int, 2>>> prev(N, vector<array<int, 2>>(M));
    vector<vector<int>> distS(N, vector<int>(M, INT_MAX));
    priority_queue<route, vector<route>, greater<route>> pq;
    distS[0][1] = g[0][1];
    //distS[1][0] = g[1][0];
    pq.push({g[0][1], 1, 0, 1, 1});
    //pq.push({g[1][0], 0, 1, 2, 1});

    while (!pq.empty()) {
        auto [dist, x, y, dir, step] = pq.top();
        pq.pop();

        if (dist != distS[y][x]) continue;

        cerr << dist << " " << x << " " << y << " " << dir << " " << step << "\n";
       
        for (int d_dir = 0; d_dir < 4; d_dir++) {
            auto [dx, dy] = dirS[d_dir];
            auto new_x = dx + x, new_y = dy + y;

            if ((step <  min_step && d_dir != dir) || 
                (step == max_step && dir == d_dir) ||
                d_dir == (dir + 2) % 4 ||
                new_x < 0 || new_y < 0 || new_x >= M || new_y >= N) continue;
        
            int new_dist = dist + g[new_y][new_x];
            if (new_dist < distS[new_y][new_x]) {
                distS[new_y][new_x] = new_dist;
                pq.push({new_dist, new_x, new_y, d_dir, (d_dir == dir ? step + 1 : 1)});
                prev[new_y][new_x] = {x, y};
            }
        }
    }

    vector<vector<char>> grid(N, vector<char>(M));

    cout << "\n";
    int curr_x = M - 1, curr_y = N - 1;
    while (!(curr_x == 0 && curr_y == 0)) {
        grid[curr_y][curr_x] = '#';
        auto [next_x, next_y] = prev[curr_y][curr_x];
        curr_x = next_x;
        curr_y = next_y;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '#') cout << '.';
            else cout << g[i][j];
        }
        cout << "\n";
    }

    return distS[N - 1][M - 1];
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

    cout << dijkstra(0, 3) << "\n";
}
