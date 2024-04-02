#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> r; getline(f, r);
    f >> s; getline(f, s);
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    long long d = stoll(s);
    cout << d;
}
