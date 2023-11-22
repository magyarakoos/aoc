#include <bits/stdc++.h>

using namespace std;

int solve(const string& s,int n) {
    for (int i = n - 1; i < s.size(); i++) {
        set<char> cs;
        for (int j = i - n; j < i && j < s.size(); j++) cs.insert(s[j]);
        if (cs.size() == n) {
            return i;
        }
    }
    return 0;
}

int main() {
    ifstream f("input");
    string s;
    f >> s;
    cout << solve(s, 4) << '\n' << solve(s, 14);
}