#include <bits/stdc++.h>

using namespace std;

#define EVAL(c) (c < 91 ? c - 38 : c - 96)

int main() {
    ifstream f("input");
    string s;
    vector<string> v;
    int p1 = 0;
    while (f >> s) {
        v.push_back(s);
        for (int i = 0; i < s.size() / 2; i++) {
            for (int j = s.size() / 2; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    p1 += EVAL(s[i]);
                    i = j = s.size();
                }
            }
        }
    }
    int p2 = 0;
    for (int i = 0; i < v.size(); i += 3) {
        for (int j = 0; j < v[i].size(); j++) {
            for (int k = 0; k < v[i+1].size(); k++) {
                for (int l = 0; l < v[i+2].size(); l++) {
                    if (v[i][j] == v[i+1][k] && v[i][j] == v[i+2][l]) {
                        p2 += EVAL(v[i][j]);
                        j = v[i].size();
                        k = v[i+1].size();
                        l = v[i+2].size();
                    }
                }
            }
        }
    }
    cout << p1 << '\n' << p2;
}
