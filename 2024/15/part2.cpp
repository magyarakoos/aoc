#include <bits/stdc++.h>
using namespace std;

int id, pid, di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
map<int, vector<array<int, 2>>> brick_to_pos;
map<array<int, 2>, int> pos_to_brick;
vector<string> m;
vector<int> instS;

bool can_move(int id, int d) {
    for (auto [i, j] : brick_to_pos[id]) {
        int ni = i + di[d], nj = j + dj[d],
            nid = pos_to_brick[{ni, nj}];
        if (m[ni][nj] == '#' ||
            (nid != id && !can_move(nid, d))) {
            return 0;
        }
    }
    return 1;
}

void move(int id, int d) {
    if (d == 2) {
        reverse(brick_to_pos[id].begin(),
                brick_to_pos[id].end());
    }
    for (auto& [i, j] : brick_to_pos[id]) {
        int ni = i + di[d], nj = j + dj[d],
            nid = pos_to_brick[{ni, nj}];
        if ((m[ni][nj] == 'O' || m[ni][nj] == '@') &&
            nid != id) {
            move(nid, d);
        }
        swap(m[i][j], m[ni][nj]);
        pos_to_brick.erase({i, j});
        pos_to_brick[{ni, nj}] = id;
        i = ni;
        j = nj;
    }
    if (d == 2) {
        reverse(brick_to_pos[id].begin(),
                brick_to_pos[id].end());
    }
}

int main() {
    string s, t = "v^><";
    while (getline(cin, s) && !s.empty()) {
        string row;
        for (int i = m.size(), j = 0; j < s.size(); j++) {
            if (s[j] == 'O') {
                brick_to_pos[++id] = {{i, j * 2},
                                      {i, j * 2 + 1}};
                pos_to_brick[{i, j * 2}] = id;
                pos_to_brick[{i, j * 2 + 1}] = id;
            }
            if (s[j] == '@') {
                row += "@.";
                brick_to_pos[++id] = {{i, j * 2}};
                pos_to_brick[{i, j * 2}] = id;
                pid = id;
            } else {
                row += string(2, s[j]);
            }
        }
        m.push_back(row);
    }
    for (char c; cin >> c;) {
        if (can_move(pid, int(c = t.find(c)))) {
            move(pid, c);
        }
    }
    int result = 0;
    for (const auto& [id, pv] : brick_to_pos) {
        if (!pv.empty() && id != pid) {
            auto [i, j] = pv[0];
            result += i * 100 + j;
        }
    }
    cout << result;
}
