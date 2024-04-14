#include <bits/stdc++.h>
using namespace std;
vector<int> v({0});

void solve(int i) {

}

int main() {
    ifstream f("input");
    string s;
    while (f >> s) {
        for (int i = 0; i < s.size(); i++) {
            v.back().push_back(s[i] == '1');
        }
        v.push_back({});
    }
    v.pop_back();
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