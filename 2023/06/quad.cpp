#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> s;
    while ((f >> s) && s[0] != 'D') {
        r += s;
    }
    long long t = stoll(r);
    r.clear();
    while (f >> s) {
        r += s;
    }
    long long d = stoll(r), p2 = 0;
    for (int i = 0; i < t; i++) {
        if (i * (t - i) > d) p2++;
    }
    cout << p2;
}
