#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a, vis, dp;
int n, m, di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int dfs1(int i, int j) {
    vis[i][j] = 1;
    if (a[i][j] == 9) return 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m ||
            a[i][j] + 1 != a[ni][nj] || vis[ni][nj]) {
            continue;
        }
        vis[i][j] += dfs1(ni, nj);
    }
    return vis[i][j] - 1;
}

int dfs2(int i, int j) {
    if (a[i][j] == 9) return dp[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m ||
            a[i][j] + 1 != a[ni][nj]) {
            continue;
        }
        if (!dp[ni][nj]) dp[ni][nj] = dfs2(ni, nj);
        dp[i][j] += dp[ni][nj];
    }
    return dp[i][j];
}

int main() {
    string s;
    while (getline(cin, s)) {
        vector<int> row;
        for (char c : s) row.push_back(c - '0');
        a.push_back(row);
    }
    n = a.size(), m = a[0].size();
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                dp.assign(n, vector<int>(m));
                vis = dp;
                p1 += dfs1(i, j);
                p2 += dfs2(i, j);
            }
        }
    }
    cout << p1 << "\n" << p2;
}
