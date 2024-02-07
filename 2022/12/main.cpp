#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;

int main() {
    ifstream f("input");
    string s;
    vector<string> grid;
    while (f >> s) {
        grid.push_back(s);
    }

    int N = grid.size(), M = grid[0].size();
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
    
    vector<vector<bool>> vis(N, vector<bool>(M));
    queue<point> q({sp});

    vis[sp[0]][sp[1]] = 1;

    
}