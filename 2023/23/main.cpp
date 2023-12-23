#include <bits/stdc++.h>
using namespace std;

using point = array<int, 2>;

vector<string> grid;
vector<vector<bool>> vis;
int N, M;

int dijkstra(point s) {
    const vector<point> moves {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, point>> pq;
    map<point, pair<int, vector<vector<bool>>>> pathS;

    pq.push({0, s});
    pathS[s] = {0, vector<vector<bool>>(N, vector<bool>(M))};

    int result = -1;

    while (!pq.empty()) {
        auto [dist, pos] = pq.front();
        pq.pop();

        if (pos[0] == N - 1 && pos[1] == M - 2) {
            result = max(result, pathS[pos].first);
        }

        for (point move : moves) {
            point new_pos{pos[0] + move[0], pos[1] + move[1]};

            if (new_pos[0] < 0 || new_pos[1] < 0 || new_pos[0] >= N || new_pos[1] >= M || grid[new_pos[0]][new_pos[1]] == '#') {
                continue;
            }

            if (pathS[pos].second[new_pos[0]][new_pos[1]]) continue;

            int new_dist = pathS[pos].first + 1;

            if (new_dist > pathS[new_pos].first) {
                pathS[new_pos].first = new_dist;
                pathS[new_pos].second = pathS[pos].second;
                pathS[new_pos].second[new_pos[0]][new_pos[1]] = 1;
                pq.push({new_dist, new_pos});
            }
        }
    }

    return result;
}

int main() {
    fstream f("input");
    string s;
    while (f >> s) grid.push_back(s);

    N = grid.size(), M = s.size();

    cout << dijkstra({0, 1});
}
