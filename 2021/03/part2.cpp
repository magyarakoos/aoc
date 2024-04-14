#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool>> v({});
    ifstream f("input");
    string s;
    while (f >> s) {
        for (char c : s) {
            v.back().push_back(c == '1');
        }
        v.push_back({});
    }
    auto [mn, mx] = minmax_element(v.begin(), v.end(),
        [](){})
}