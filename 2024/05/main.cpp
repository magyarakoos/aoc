#include <bits/stdc++.h>
using namespace std;

#define has(v, x) (find(v.begin(), v.end(), x) != v.end())
int main() {
    vector<vector<int>> g(100);
    string s;
    int p1 = 0, p2 = 0, fp = 1;
    while (getline(cin, s)) {
        if (!s.size()) {
            fp = 0;
            continue;
        }
        replace(s.begin(), s.end(), '|', ' ');
        replace(s.begin(), s.end(), ',', ' ');
        istringstream iss(s);
        if (fp) {
            int u, v;
            iss >> u >> v;
            g[u].push_back(v);
        } else {
            vector<int> a;
            int u, ok = 1;
            while (iss >> u) a.push_back(u);
            for (int i = 0; i < a.size(); i++) {
                for (int j = 0; j < i; j++) {
                    ok &= !has(g[a[i]], a[j]);
                }
            }
            if (ok) {
                p1 += a[a.size() / 2];
                continue;
            }
            vector<bool> vis(100);
            vector<int> result;
            function<void(int)> dfs = [&](int u) {
                vis[u] = 1;
                for (int v : g[u]) {
                    if (has(a, v) && !vis[v]) dfs(v);
                }
                result.push_back(u);
            };
            for (int u : a) {
                if (!vis[u]) dfs(u);
            }
            p2 += result[a.size() / 2];
        }
    }
    cout << p1 << "\n" << p2;
}
