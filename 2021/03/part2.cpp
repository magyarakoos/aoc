#include <bits/stdc++.h>
using namespace std;
int w;

void solve(int i, vector<int> v) {

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