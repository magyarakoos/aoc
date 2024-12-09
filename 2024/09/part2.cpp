#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    vector<int> a, ca;
    while (cin >> c) a.push_back(c - '0');
    ca = a;
    vector<vector<array<int, 2>>> blk(a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        if (i % 2) continue;
        for (int j = 1; j < i; j += 2) {
            if (a[j] >= a[i]) {
                blk[j].push_back({i / 2, a[i]});
                a[j] -= a[i];
                a[i] = 0;
                break;
            }
        }
        if (a[i] > 0) {
            blk[i].push_back({i / 2, a[i]});
            a[i] = 0;
        }
    }
    long long result = 0;
    for (int i = 0, l = 0; i < a.size(); i++) {
        int blksz = 0;
        for (int j = 0; j < blk[i].size(); j++) {
            blksz += blk[i][j][1];
            for (int k = 0; k < blk[i][j][1]; k++) {
                result += blk[i][j][0] * l++;
            }
        }
        l += ca[i] - blksz;
    }
    cout << result;
}
