#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a, vis;
int n, m, di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int dfs(int i, int j) {
    vis[i][j] = 1;
    if (a[i][j] == 9) return 1;
    int result = 0;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m ||
            a[i][j] + 1 != a[ni][nj] || vis[ni][nj]) {
            continue;
        }
        result += dfs(ni, nj);
    }
    return result;
}

int main() {
    string s;
    while (getline(cin, s)) {
        vector<int> row;
        for (char c : s) row.push_back(c - '0');
        a.push_back(row);
    }
    n = a.size(), m = a[0].size();
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                vis.assign(n, vector<int>(m));
                result += dfs(i, j);
            }
        }
    }
    cout << result;
}
