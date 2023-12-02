#include <bits/stdc++.h>
using namespace std;

int main() {
    const vector<char> del{' ', ':', ','};
    ifstream f("input");
    string s;
    vector<pair<int, vector<vector<pair<int, string>>>>> input;
    while (getline(f, s)) {
        vector<string> v;
        string curr;
        for (char ch : s) {
            if (find(del.begin(), del.end(), ch) != del.end()) {
                if (!curr.empty()) {
                    v.push_back(curr);
                    curr.clear();
                }
            } else curr += ch;
        }
        if (!curr.empty()) v.push_back(curr);
        vector<vector<pair<int, string>>> vp;
        int n;
        for (int i = 2; i < v.size(); i++) {
            if (vp.empty()) vp.push_back({});
            if (v[i].back() == ';') {
                vp.back().push_back({n, v[i].substr(0, v[i].size() - 1)});
                vp.push_back({});
            } else {
                if (i % 2 == 0) {
                    n = stoi(v[i]);
                } else {
                    vp.back().push_back({n, v[i]});
                }
            }
        }
        input.push_back({stoi(v[1]), vp});
    }
    int p1 = 0, p2 = 0;
    for (const auto& p : input) {
        bool valid = 1;
        int mrc = 0, mgc = 0, mbc = 0;
        for (const auto& v : p.second) {
            int rc = 0, gc = 0, bc = 0;
            for (const auto& pp : v) {
                if (pp.second == "red") rc += pp.first;
                if (pp.second == "green") gc += pp.first;
                if (pp.second == "blue") bc += pp.first;
            }
            if (rc > 12 || gc > 13 || bc > 14) valid = 0;
            mrc = max(mrc, rc);
            mgc = max(mgc, gc);
            mbc = max(mbc, bc);
        }
        if (valid) p1 += p.first;
        p2 += (mrc * mgc * mbc);
    }
    cout << p1 << '\n' << p2;
}