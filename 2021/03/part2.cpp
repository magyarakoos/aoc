#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> v({{}});
    vector<int> oc;
    ifstream f("input");
    string s;
    while (f >> s) {
        if (oc.empty()) oc.resize(s.size());
        for (int i = 0; i < s.size(); i++) {
            v.back().push_back(s[i] == '1');
            oc[i] += v.back().back();
        }
        v.push_back({});
    }
    v.pop_back();
    for (int& x : oc) x = x >= v.size() - x;
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
    for (int x : *mn) cout << x;
    cout << "\n";
    for (int x : *mx) cout << x;
    cout << "\n";
}