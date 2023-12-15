#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f("input");
    string s;
    f >> s;
    replace(s.begin(), s.end(), ',', ' ');
    stringstream ss(s);
    array<vector<pair<string, int>>, 256> boxes;
    while (ss >> s) {
        int hash = 0, i;
        for (i = 0; s[i] != '=' && s[i] != '-'; i++) {
            hash += s[i];
            hash *= 17;
            hash %= 256;
        }
        if (s[i] == '-') {
            for (int j = 0; j < boxes[hash].size(); j++) {
                if (boxes[hash][j].first == s.substr(0, s.size() - 1)) {
                    boxes[hash].erase(
                        boxes[hash].begin() +
                        j
                    );
                    break;
                }
            }
        } else {
            int fl = s[i + 1] - '0', j;
            for (j = 0; j < boxes[hash].size(); j++) {
                if (boxes[hash][j].first == s.substr(0, s.size() - 2)) {
                    boxes[hash][j].second = fl;
                    break;
                }
            }
            if (j == boxes[hash].size()) {
                boxes[hash].push_back({s.substr(0, s.size() - 2), fl});
            }
        }
    }
    int p2 = 0;
    for (int i = 0; i < boxes.size(); i++) {
        for (int j = 0; j < boxes[i].size(); j++) {
            p2 += (i + 1) * (j + 1) * boxes[i][j].second;
        }
    }
    cout << p2;
}
