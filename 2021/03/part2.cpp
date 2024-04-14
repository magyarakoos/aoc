#include <bits/stdc++.h>
using namespace std;
int w;

int solve(int i, vector<int> v, function<bool(int, int)> f) {
    if (v.size() == 1) {
        return v[0];
    }
    int oc = 0;
    for (int x : v) {
        oc += (x >> i) & 1;
    }
    vector<int> nv;
    for (int x : v) {
        if (f(v.size() - oc, oc)) {
            if ((x >> i) & 1) {
                nv.push_back(x);
            }
        } else {
            if (!((x >> i) & 1)) {
                nv.push_back(x);
            }
        }
    }
    return solve(i - 1, nv, f);
}

int main() {
    ifstream f("input");
    string s;
    vector<int> v;
    while (f >> s) {
        v.push_back(0);
        w = s.size();
        for (int i = 0; i < s.size(); i++) {
            v.back() |= ((s[i] == '1') << (s.size() - i - 1));
        }
    }
    cout << 
        solve(w - 1, v, [](int zc, int oc){ return zc <= oc; }) *
        solve(w - 1, v, [](int zc, int oc){ return oc < zc; });
}