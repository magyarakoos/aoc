#include <bits/stdc++.h>
using namespace std;

vector<string> m;
int si, sj, ei, ej;

int solve(int maxd) {
    int n = m.size();
    int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

    vector distS(n, vector<int>(n, 1e9));
    distS[si][sj] = 0;
    queue<array<int, 2>> q({{si, sj}});
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && nj >= 0 && ni < n & nj < n &&
                distS[ni][nj] >= distS[i][j] + 1 &&
                m[ni][nj] != '#') {
                distS[ni][nj] = distS[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }

    int result = 0, md = distS[ei][ej];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distS[i][j] == 1e9) continue;
            for (int di = -maxd; di <= maxd; di++) {
                for (int dj = -maxd; dj <= maxd; dj++) {
                    int d = abs(di) + abs(dj), ni = i + di,
                        nj = j + dj;
                    if (d <= maxd && ni >= 0 && nj >= 0 &&
                        ni < n && nj < n &&
                        distS[ni][nj] < 1e9) {
                        result += (distS[i][j] -
                                       distS[ni][nj] + d <=
                                   -100);
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    for (string s; getline(cin, s);) {
        int sp = s.find('S'), ep = s.find('E');
        if (sp != s.npos) si = m.size(), sj = sp;
        if (ep != s.npos) ei = m.size(), ej = ep;
        m.push_back(s);
    }
    cout << solve(2) << "\n" << solve(20);
}
