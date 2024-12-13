#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    string s;
    vector<array<ll, 2>> v;
    while (getline(cin, s)) {
        if (s.empty()) continue;
        ll x, y;
        for (char& c : s) {
            if (!isdigit(c)) c = ' ';
        }
        istringstream iss(s);
        iss >> x >> y;
        v.push_back({x, y});
    }
    auto f = [&](int i) {
        ll na = v[i][0] * v[i - 1][1] -
                v[i][1] * v[i - 1][0],
           da = v[i - 2][0] * v[i - 1][1] -
                v[i - 2][1] * v[i - 1][0],
           nb = (v[i][0] - na / da * v[i - 2][0]),
           db = v[i - 1][0];
        return (na % da == 0 && nb % db == 0) *
               (na / da * 3 + nb / db);
    };
    ll p1 = 0, p2 = 0;
    for (int i = 2; i < v.size(); i += 3) {
        p1 += f(i);
        v[i][0] += 1e13;
        v[i][1] += 1e13;
        p2 += f(i);
    }
    cout << p1 << "\n" << p2;
}
