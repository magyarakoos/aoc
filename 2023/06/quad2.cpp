#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> s;
    while (f >> s && s[0] != 'D') {
        r += s;
    }
    long long t = stoll(r);
    r = "";
    while (f >> s) {
        r += s;
    }
    long long d = stoll(r), p2 = 0;

    cout << p2;
}
