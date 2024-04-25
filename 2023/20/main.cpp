#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> g;
vector<vector<pair<string, bool>>> rec;
map<string, pair<char, bool>> m;

int main() {
    ifstream f("input");
    string s;
    while (getline(f, s)) {
        replace(s.begin(), s.end(), '')
        istringstream iss(s);
        vector<string> t;
        while (iss >> s) t.push_back(s);
        m[t[0].substr(1)] = {t[0][0], 0};
    }
}