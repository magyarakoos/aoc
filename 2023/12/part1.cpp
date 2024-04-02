#include <bits/stdc++.h>
using namespace std;

bool valid(string s, const vector<int>& g) {
    replace(s.begin(), s.end(), '.', ' ');
    stringstream ss(s);
    int i = 0;
    for (; ss >> s; i++) {
        if (s.size() != g[i]) return 0;
    }
    return i == g.size();
}

void get_combs(vector<string>& cmbs, string curr, int len) {
    if (!len) {
        cmbs.push_back(curr);
        return;
    }
    get_combs(cmbs, curr + "#", len - 1);
    get_combs(cmbs, curr + ".", len - 1);
}

int main() {
    fstream f("input");
    string s, t;
    int p1 = 0;
    while (f >> s >> t) {
        vector<int> groups;
        replace(t.begin(), t.end(), ',', ' ');
        stringstream ss(t);
        while (ss >> t) {
            groups.push_back(stoi(t));
        }
        int curr = 0;
        vector<int> spots;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '?') spots.push_back(i);
        }
        vector<string> cmbs;
        get_combs(cmbs, "", spots.size());
        for (string& cmb : cmbs) {
            string t = s;
            for (int i = 0; i < spots.size(); i++) {
                t[spots[i]] = cmb[i];
            }
            p1 += valid(t, groups);
        }
    }
    cout << p1;
}