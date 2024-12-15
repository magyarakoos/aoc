#include <bits/stdc++.h>
using namespace std;

int pi, pj, di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
vector<string> m;
vector<int> instS;

bool move(int i, int j, int d) {
    int ni = i + di[d], nj = j + dj[d];
    if (m[ni][nj] == '#') return 0;
    if (m[ni][nj] == 'O') move(ni, nj, d);
    if (m[ni][nj] == '.') {
        swap(m[i][j], m[ni][nj]);
        return 1;
    }
    return 0;
}

int main() {
    string s, t = "v^><";
    while (getline(cin, s) && !s.empty()) {
        int j = s.find('@');
        if (j != s.npos) {
            s[j] = '.';
            pi = m.size(), pj = j;
        }
        m.push_back(s);
    }
    for (char c; cin >> c;) {
        if (move(pi, pj, int(c = t.find(c)))) {
            pi += di[c], pj += dj[c];
        }
    }
    int result = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            result += (m[i][j] == 'O') * (i * 100 + j);
        }
    }
    cout << result;
}
