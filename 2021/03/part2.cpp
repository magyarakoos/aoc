#include <bits/stdc++.h>
using namespace std;
int w;

void solve(int i, vector<int> v) {
    if (i == -1) {
        cout << bitset<5>(v[0]);
        return;
    }
    cout << i << " : ";
    for (int x : v) cout << bitset<5>(x) << " ";
    cout << "\n";
    int oc = 0, zc = 0;
    for (int x : v) {
        oc += (x >> i) & 1;
        zc += !((x >> i) & 1);
    }
    vector<int> nv;
    for (int x : v) {
        if (oc >= zc) {
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
        for (int i = 0; i < s.size(); i++) {
            v.back() |= ((s[i] == '1') << (s.size() - i - 1));
        }
    }
    solve(w - 1, v);
}