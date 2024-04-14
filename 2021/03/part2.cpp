#include <bits/stdc++.h>
using namespace std;
int w;

void solve(int i, vector<int> v) {
    if (i == -1) {
        for (int i = w - 1; i >= 0; i--) {
            cout << (v[0] >> i);
        }
        cout << "\n";
    }
    int oc = 0;
    for (int x : v) {
        oc += (x >> i) & 1;
    }
    oc = oc >= v.size() - oc;
    vector<int> nv;
    for (int x : v) {
        if (oc && (x >> i) & 1 ||)
    }
}

int main() {
    ifstream f("input");
    string s;
    vector<int> v;
    while (f >> s) {
        v.push_back(0);
        w = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            v.back() |= ((s[i] == '1') << i);
        }
    }
    auto [mn, mx] = minmax_element(v.begin(), v.end(),
        [&](auto a, auto b) {
            for (int i = 0; i < a.size(); i++) {
                if (oc[i]) {
                    if (b[i] && !a[i]) {
                        return true;
                    }
                } else {
                    if (!b[i] && a[i]) {
                        return true;
                    }
                }
            }
            return false;
        }
    );
}