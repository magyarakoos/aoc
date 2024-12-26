#include <bits/stdc++.h>
using namespace std;

map<string, pair<array<string, 2>, int>> edgeS;
map<string, vector<string>> g;
map<string, int> valS;
deque<string> topS;
set<string> vis;

void dfs(string u) {
    vis.insert(u);
    for (string v : g[u]) {
        if (!vis.count(v)) dfs(v);
    }
    if (!valS.count(u)) topS.push_front(u);
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s.empty()) break;
        valS[s.substr(0, 3)] = s[5] - '0';
    }
    while (getline(cin, s)) {
        string ua, ub, op, v, opS = "AOX";
        istringstream(s) >> ua >> op >> ub >> v >> v;
        edgeS[v] = {{ua, ub}, (int)opS.find(op[0])};
        g[ua].push_back(v);
        g[ub].push_back(v);
    }
    for (auto [u, _] : valS) {
        if (!vis.count(u)) dfs(u);
    }
    vector<pair<string, int64_t>> zS;
    for (string u : topS) {
        auto [vx, op] = edgeS[u];
        int a = valS[vx[0]], b = valS[vx[1]];
        valS[u] = (op == 0   ? a && b
                   : op == 1 ? a || b
                             : a != b);
        if (u[0] == 'z') zS.push_back({u, valS[u]});
    }
    sort(zS.begin(), zS.end());
    int64_t A = 0, B = 0, C = 0;
    for (int i = 0; i < zS.size(); i++) {
        C |= zS[i].second << i;
    }
    cout << C;
}
