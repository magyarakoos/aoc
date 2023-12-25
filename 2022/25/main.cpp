#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, char> m {
        {'0', 0}, {'1', 1}, {'2', 2}, {'-', -1}, {'=', -2},
    }, n {
        {0, '0'}, {1, '1'}, {2, '2'}, {-1, '-'}, {-2, '='}
    };
    fstream f("input");
    string s, t;
    long long sum = 0;
    while (f >> s) {
        for (int i = s.size(); i > 0; i--) {
            sum += m[s[i - 1]] * pow(5, s.size() - i);
        }
    }
    while (sum > 0) {
        long long d = ((sum + 2) % 5) - 2;
        t = n[d] + t;
        sum = (sum - d) / 5;
    }
    cout << t;
}
