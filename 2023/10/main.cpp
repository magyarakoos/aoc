#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;
#define x first
#define y second

vector<string> v;
vector<point> vis;
point start;
int N, M;

const vector<string> joints {
    "|7F",
    "|LJ",
    "-FL",
    "-7J"
};

void validate(bool& u, bool& d, bool& l, bool& r, point p) {
    u = (p.x &&
        joints[1].find(
            v[p.x][p.y]
        ) != joints[1].npos &&
        joints[0].find(
            v[p.x - 1][p.y]
        ) != joints[0].npos
    );
    d = (p.x + 1 < N &&
        joints[1].find(
            v[p.x + 1][p.y]
        ) != joints[1].npos &&
        joints[0].find(
            v[p.x][p.y]
        ) != joints[0].npos
    );
    l = (p.y &&
        joints[2].find(
            v[p.x][p.y - 1]
        ) != joints[2].npos &&
        joints[3].find(
            v[p.x][p.y]
        ) != joints[3].npos
    );
    r = (p.y + 1 < M && 
        joints[3].find(
            v[p.x][p.y + 1]
        ) != joints[3].npos &&
        joints[2].find(
            v[p.x][p.y]
        ) != joints[2].npos
    );
}

void set_start() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (v[i][j] == 'S') {
                start = {i, j};
                bool u, d, l, r;
                validate(u, d, l, r, start);
                v[i][j] = (
                    u && d ? '|' :
                    l && r ? '-' :
                    d && r ? 'F' :
                    d && l ? '7' :
                    u && l ? 'J' :
                    'L'
                );
                return;
            }
        }
    }
}

bool cont(point p) {
    return find(vis.begin(), vis.end(), p) != vis.end();
}

void flood_fill(vector<vector<char>>& grid, point p) {
    if (p.x < 0 || p.x >= N * 2 - 1 || p.y < 0 || p.y >= M * 2 - 1) {
        return;
    }
    if (grid[p.x][p.y] == '#' || grid[p.x][p.y] == ' ') {
        return;
    }
    grid[p.x][p.y] = ' ';
    flood_fill(grid, {p.x + 1, p.y});
    flood_fill(grid, {p.x - 1, p.y});
    flood_fill(grid, {p.x, p.y + 1});
    flood_fill(grid, {p.x, p.y - 1});
}

void dfs(point p) {
    vis.push_back(p);
    bool u, d, l, r;
    validate(u, d, l, r, p);
    if (u && !cont({p.x - 1, p.y})) dfs({p.x - 1, p.y});
    else if (d && !cont({p.x + 1, p.y})) dfs({p.x + 1, p.y});
    else if (l && !cont({p.x, p.y - 1})) dfs({p.x, p.y - 1});
    else if (r && !cont({p.x, p.y + 1})) dfs({p.x, p.y + 1});
    else return;
}

int main() {
    ifstream f("input");
    string s;
    while (f >> s) v.push_back(s);
    N = v.size();
    M = v[0].size();
    set_start();
    dfs(start);
    vector<vector<char>> exp(N * 2 - 1, vector<char>(M * 2 - 1, '~'));
    for (int i = 0; i < vis.size(); i++) {
        exp[vis[i].x * 2][vis[i].y * 2] = '#';
        if (i) {
            if (vis[i].y == vis[i - 1].y) {
                exp[min(vis[i].x, vis[i - 1].x) * 2 + 1][vis[i].y * 2] = '#';
            } else {
                exp[vis[i].x * 2][min(vis[i].y, vis[i - 1].y) * 2 + 1] = '#';
            }
        }
    }
    if (vis.front().y == vis.back().y) {
        exp[min(vis.front().x, vis.back().x) * 2 + 1][vis.back().y * 2] = '#';
    } else {
        exp[vis.back().x * 2][min(vis.front().y, vis.back().y) * 2 + 1] = '#';
    }
    for (int i = 0; i < N * 2 - 1; i++) {
        flood_fill(exp, {i, 0});
        flood_fill(exp, {i, M * 2 - 2});
    }
    for (int i = 0; i < M * 2 - 1; i++) {
        flood_fill(exp, {0, i});
        flood_fill(exp, {N * 2 - 2, i});
    }
    int p2 = 0;
    for (int i = 0; i < N * 2 - 1; i += 2) {
        for (int j = 0; j < M * 2 - 1; j += 2) {
            p2 += exp[i][j] == '~';
        }
    }
    cout << vis.size() / 2 << '\n' << p2;
}
