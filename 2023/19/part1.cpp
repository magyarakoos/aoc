#include <bits/stdc++.h>
using namespace std;

struct Rule {
    char prop;
    char oper;
    int cmp;
    string sentence;
};

struct Part {
    int x;
    int m;
    int a;
    int s;
}; // 🎄

int main() {
    fstream f("input");
    string s;
    map<string, vector<Rule>> rules;
    while (getline(f, s) && s != "") {
        string key = s.substr(0, s.find('{'));
        replace(s.begin(), s.end(), ',', ' ');
        stringstream ss(s.substr(s.find('{') + 1, s.size() - 2 - key.size()));
        while (ss >> s) {
            if (s.find('<') == s.npos && s.find('>') == s.npos) {
                rules[key].push_back({0, 0, 0, s});
            } else {
                rules[key].push_back({
                    s[0],
                    s[1],
                    stoi(s.substr(2, s.find(':') - 2)),
                    s.substr(s.find(':') + 1)
                });
            }
        }
    }
    vector<Part> parts;
    while (f >> s) {
        replace(s.begin(), s.end(), ',', ' ');
        stringstream ss(s);
        parts.push_back({});
        ss >> s;
        parts.back().x = stoi(s.substr(3));
        ss >> s;
        parts.back().m = stoi(s.substr(2));
        ss >> s;
        parts.back().a = stoi(s.substr(2));
        ss >> s;
        parts.back().s = stoi(s.substr(2, s.size() - 3));
    }
    int p1 = 0;
    for (const Part& p : parts) {
        string entry = "in";
        for (bool br = 0; !br;) {
            for (const Rule& r : rules[entry]) {
                if (!r.oper && r.sentence == "R") {
                    br = 1;
                    break;
                }
                if (!r.oper && r.sentence == "A") {
                    p1 += p.x + p.m + p.a + p.s;
                    br = 1;
                    break;
                }
                int val = (
                    r.prop == 'x' ? p.x :
                    r.prop == 'm' ? p.m :
                    r.prop == 'a' ? p.a :
                    p.s
                );
                if (!r.prop || (r.oper == '<' && val < r.cmp) || (r.oper == '>' && val > r.cmp)) {
                    if (r.sentence == "R") br = 1;
                    if (r.sentence == "A") {
                        p1 += p.x + p.m + p.a + p.s;
                        br = 1;
                    }
                    entry = r.sentence;
                    break;
                }
            }
        }
    }
    cout << p1;
}
