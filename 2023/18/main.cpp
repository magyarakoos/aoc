#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
    ifstream f("input");
    string s;
    ll result = 0;
    array<ll, 2> p{0, 0};
    while (getline(f, s) && s != "") {
        istringstream ss(s);
        for (int i = 0; i < 3; i++) ss >> s;
        int dir = s[7] - '0', len = stoi(s.substr(2, 5), 0, 16);
        array<ll, 2> np = {dx[dir] * len + p[0], dy[dir] * len + p[1]};
        result += len + p[0] * np[1] - p[1] * np[0];
        p = np;
    }
    cout << result / 2 + 1;
}
