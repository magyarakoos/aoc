#include <bits/stdc++.h>
using namespace std;
int w;

void solve(int i, vector<int> v) {
    if (i == -1) {
        cout << bitset<5>(v[0]);
        return;
    }
    int oc = 0;
    for (int x : v) {
        oc += (x >> i) & 1;
    }
    oc = oc >= v.size() - oc;
    vector<int> nv;
    for (int x : v) {
        if (oc) {
            if ((x >> i) & 1) {
                nv.push_back(x);
            }
        } else {
            if (!((x >> i) & 1)) {
                nv.push_back(x);
            }
        }
    }
    solve(i - 1, nv);
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
    solve(w - 1, v);
}