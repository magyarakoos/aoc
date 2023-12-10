#include <bits/stdc++.h>
using namespace std;

using point = pair<int, int>;
#define x first
#define y second

vector<string> v;
map<point, vector<point>> g;
set<point> vis;
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
    return vis.find(p) != vis.end();
}

void dfs(point p) {
    vis.insert(p);
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
    cout << vis.size() / 2;
}
