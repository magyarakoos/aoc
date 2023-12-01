#include <bits/stdc++.h>
using namespace std;

int main() {
    const vector<pair<string, string>> m{
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };
    ifstream f("input");
    string s;
    int p1 = 0, p2 = 0;
    while (f >> s) {
        char c, d;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                c = s[i];
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (isdigit(s[i])) {
                d = s[i];
                break;
            }
        }
        p1 += stoi(string{c, d});
        string t;
        for (int i = 0; i < s.size(); i ++) {
            if (isdigit(s[i])) {
                t += s[i];
            } else {
                for (const pair<string, string>& p : m) {
                    if (s.substr(i, p.first.size()) == p.first) {
                        t += p.second;
                    }
                }
            }
        }
        p2 += stoi(string{t[0], t.back()});
    }
    cout << p1 << '\n' << p2;
}
