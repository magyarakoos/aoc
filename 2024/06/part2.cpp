#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> a;
    vector<vector<int>> vd;
    string s;
    while (getline(cin, s)) a.push_back(s);
    int si, sj, n = a.size(), di[] = {-1, 0, 1, 0},
                dj[] = {0, 1, 0, -1}, result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '^') {
                si = i;
                sj = j;
                break;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int l = 0; l < n; l++) {
            int i = si, j = sj, d = 0;
            vd.assign(n, vector<int>(n, 0));
            while (i >= 0 && j >= 0 && i < n && j < n) {
                while (a[i][j] == '#' ||
                       (i == k && j == l)) {
                    i -= di[d], j -= dj[d];
                    d = (d + 1) % 4;
                    i += di[d], j += dj[d];
                }
                if (vd[i][j] == d + 1) {
                    result++;
                    break;
                }
                vd[i][j] = d + 1;
                i += di[d], j += dj[d];
            }
        }
    }
    cout << result;
}
