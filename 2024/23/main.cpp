#include <bits/stdc++.h>
using namespace std;

map<string, set<string>> g;
set<set<string>> p1;
set<string> vis, p2;

void dfs(string u) {
    vis.insert(u);
    for (string v : g[u]) {
        if (vis.count(v)) continue;
        for (string w : vis) {
            if (!g[v].count(w)) goto nxt;
        }
        dfs(v);
    nxt:
        continue;
    }
}

int main() {
    string s;
    while (getline(cin, s)) {
        string u = s.substr(0, 2), v = s.substr(3);
        g[u].insert(v);
        g[v].insert(u);
    }
    for (const auto& [u, vx] : g) {
        if (u[0] != 't') continue;
        for (string va : vx) {
            for (string vb : vx) {
                if (!g[va].count(vb) || va == vb) continue;
                p1.insert({u, va, vb});
            }
        }
        vis.clear();
        dfs(u);
        if (p2.size() < vis.size()) p2 = vis;
    }
    cout << p1.size() << "\n";
    for (auto x : p2) cout << x << ",";
    cout << "\b \n";
}
