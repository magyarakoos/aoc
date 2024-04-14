#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> v({});
    vector<int> oc;
    ifstream f("input");
    string s;
    while (f >> s) {
        for (int i = 0; i < s.size(); i++) {
            v.back().push_back(s[i] == '1');
        }
        v.push_back({});
    }
    auto [mn, mx] = minmax_element(v.begin(), v.end(),
        [](){})
}