#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, vector<string>> g;
map<string, vector<pair<string, bool>>> rec;
map<string, pair<char, bool>> m;
ll hcnt, lcnt;

void bfs() {
    
}

int main() {
    ifstream f("input");
    string s;
    while (getline(f, s)) {
        replace(s.begin(), s.end(), ',', ' ');
        istringstream iss(s);
        vector<string> t;
        while (iss >> s) t.push_back(s);
        m[t[0].substr(1)] = {t[0][0], 0};
        for (size_t i = 2; i < t.size(); i++) {
            g[t[0].substr(1)].push_back(t[i]);
            rec[t[i]].push_back({t[0].substr(1), 0});
        }
    }
    
    for (int i = 0; i < 1000; i++) {
        bfs();
    }
}