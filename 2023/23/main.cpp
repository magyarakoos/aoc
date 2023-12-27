#include <bits/stdc++.h>
using namespace std;

using point = array<int, 2>;
using route = array<int, 3>;

// it's important to note here that this does not work.
int main() {
    fstream f("input");
    string s;
    vector<string> grid;
    while (f >> s) grid.push_back(s);

    int N = grid.size(), M = s.size();
    const vector<point> moveS {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    priority_queue<route, vector<route>, greater<route>> pq;
    vector<vector<bool>> vis(N, vector<bool>(M));
    map<point, int> distS;
    pq.push({0, 0, 1});
    distS[{0, 1}] = 0;

    while (!pq.empty()) {
        route next = pq.top();
        point pos = {next[1], next[2]};
        int dist = next[0];
        pq.pop();

        vis[pos[0]][pos[1]] = 1;

        if (pos[0] == N - 1 && pos[1] == M - 2) {
            cout << -distS[pos] << endl;
            exit(0);
        }

        for (point move : moveS) {

            point new_pos = {pos[0] + move[0], pos[1] + move[1]};

            if (new_pos[0] < 0 || new_pos[1] < 0 || new_pos[0] >= N || new_pos[1] >= M ||
                grid[new_pos[0]][new_pos[1]] == '#' || vis[new_pos[0]][new_pos[1]]
            ) continue;
            
            int new_dist = distS[pos] - 1;

            if (new_dist < distS[new_pos]) {
                distS[new_pos] = new_dist;
                pq.push({new_dist, new_pos[0], new_pos[1]});
            }
        }
    }
}
