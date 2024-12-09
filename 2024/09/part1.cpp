#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    vector<int> a;
    while (cin >> c) a.push_back(c - '0');
    vector<vector<array<int, 2>>> blk(a.size());
    for (int i = a.size() - 1, j = 1; i >= 0; i--) {
        if (i % 2) continue;
        while (a[i] > 0 && j < i) {
            if (a[j] >= a[i]) {
                blk[j].push_back({i / 2, a[i]});
                a[j] -= a[i];
                a[i] = 0;
                break;
            } else {
                blk[j].push_back({i / 2, a[j]});
                a[i] -= a[j];
                j += 2;
            }
        }
        blk[i].push_back({i / 2, a[i]});
    }
    long long result = 0, i = 0;
    for (auto row : blk) {
        for (auto [ty, db] : row) {
            while (db--) result += ty * i++;
        }
    }
    cout << result;
}
