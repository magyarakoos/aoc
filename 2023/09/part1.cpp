#include <bits/stdc++.h>
using namespace std;

vector<int> diffmask(const vector<int>& v) {
    vector<int> diff(v.size() - 1);
    for (int i = 1; i < v.size(); i++) {
        diff[i - 1] = v[i] - v[i - 1];
    }
    return diff;
}

int main() {
    vector<vector<int>> v;
    ifstream f("input");
    string s;
    while (getline(f, s)) {
        v.push_back({});
        stringstream ss(s);
        while (ss >> s) {
            v.back().push_back(stoi(s));
        }
    }
    int p1 = 0;
    for (const vector<int>& line : v) {
        vector<vector<int>> diffs({line});
        while (any_of(diffs.back().begin(), diffs.back().end(), 
        [](int n){ return n != 0; })) {
            diffs.push_back(diffmask(diffs.back()));
        }
        diffs.back().push_back(0); // starting zero
        for (int i = diffs.size() - 2; i >= 0; i--) {
            diffs[i].push_back(diffs[i].back() + diffs[i + 1].back());
        }
        p1 += diffs[0].back();
    }
    cout << p1;
}