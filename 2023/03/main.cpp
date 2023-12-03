#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s;
    vector<string> v;
    while (f >> s) v.push_back(s);
    int p1 = 0, p2 = 0, N = v.size(), M = v[0].size();
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (isdigit(v[x][y])) {
                int b = y;
                while (y < M - 1 && isdigit(v[x][y+1])) y++;
                for (int i = b; i <= y; i++) {
                    for (int dx = max(x - 1, 0); dx <= min(x + 1, N - 1); dx++) {
                        for (int dy = max(i - 1, 0); dy <= min(i + 1, M - 1); dy++) {
                            if ((x != dx || i != dy) && !isdigit(v[dx][dy]) && v[dx][dy] != '.') {
                                p1 += stoi(v[x].substr(b, y - b + 1));
                                dx = N; 
                                dy = i = M;
                            }
                        }
                    }
                }
            }
            if (v[x][y] == '*') {
                vector<vector<bool>> visited(N, vector<bool>(M));
                int c = 0, prod = 1;
                for (int dx = max(x - 1, 0); dx <= min(x + 1, N - 1); dx++) {
                    for (int dy = max(y - 1, 0); dy <= min(y + 1, M - 1); dy++) {
                        if ((x != dx || y != dy) && isdigit(v[dx][dy]) && !visited[dx][dy]) {
                            visited[dx][dy] = 1;
                            int b = dy, e = dy;
                            bool bdec, einc;
                            while (b && e < M - 1 && ((bdec = isdigit(v[dx][b - 1])) || (einc = isdigit(v[dx][e + 1])))) {
                                if (bdec) {
                                    visited[dx][--b] = 1;
                                } else {
                                    visited[dx][++e] = 1;
                                }
                            }
                            prod *= stoi(v[dx].substr(b, e - b + 1));
                            c++;
                        }
                    }
                }
                if (c == 2) p2 += prod;
            }
        }
    }
    cout << p1 << '\n' << p2;
}
