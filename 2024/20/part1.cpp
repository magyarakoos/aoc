#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> m;
    int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1}, si, sj,
        ei, ej;
    string s;
    while (getline(cin, s)) {
        int sp = s.find('S'), ep = s.find('E');
        if (sp != s.npos) si = m.size(), sj = sp;
        if (ep != s.npos) ei = m.size(), ej = ep;
        m.push_back(s);
    }
    int n = m.size(), bl = 0, result = 0;
    vector<int> distS;
    queue<array<int, 6>> q({{si, sj, -1, -1, 0, 0}});
    while (!q.empty()) {
        auto [i, j, pi, pj, d, cs] = q.front();
        q.pop();
        if (bl && bl < d) continue;
        if (i == ei && j == ej) {
            if (!cs) bl = d;
            distS.push_back(d);
            continue;
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni == pi && nj == pj || ni < 0 || nj < 0 ||
                ni >= n || nj >= n)
                continue;
            if (m[ni][nj] != '#') {
                q.push({ni, nj, i, j, d + 1, cs});
            }
            if (!cs) { q.push({ni, nj, i, j, d + 1, 1}); }
        }
    }
    for (int x : distS) result += x + 100 <= bl;
    cout << result;
}
