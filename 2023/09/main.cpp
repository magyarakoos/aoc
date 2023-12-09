#include <bits/stdc++.h>
using namespace std;

vector<int> diffmask(const vector<int>& v) {
    vector<int> diff(v.size() - 1);
    for (int i = 1; i < v.size(); i++) {
        diff[i - 1] = v[i] - v[i - 1];
    }
    return diff;
}

int p1(vector<vector<int>> diffs) {
    diffs.back().push_back(0); // starting zero
    for (int i = diffs.size() - 2; i >= 0; i--) {
        diffs[i].push_back(diffs[i].back() + diffs[i + 1].back());
    }
    return diffs[0].back();
}

int p2(vector<vector<int>> diffs) {
    diffs.back().push_back(0);
    for (int i = diffs.size() - 2; i >= 0; i--) {
        diffs[i].insert(
            diffs[i].begin(),
            diffs[i].front() - diffs[i + 1].front()
        );
    }
    return diffs[0].front();
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
    int _p1 = 0, _p2 = 0;
    for (const vector<int>& line : v) {
        vector<vector<int>> diffs({line});
        while (any_of(diffs.back().begin(), diffs.back().end(), 
        [](int n){ return n != 0; })) {
            diffs.push_back(diffmask(diffs.back()));
        }
        _p1 += p1(diffs);
        _p2 += p2(diffs);
    }
    cout << _p1 << '\n' << _p2;
}