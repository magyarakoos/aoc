#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> r; getline(f, r);
    f >> s; getline(f, s);
    r.erase(remove_if(r.begin(), r.end(), ::isspace), r.end());
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    double
        t = stold(r),
        d = stold(s),
        x1 = (t - sqrt(pow(t, 2) - 4 * d)) / 2,
        x2 = (t + sqrt(pow(t, 2) - 4 * d)) / 2;
    x1 = ceil(x1)  + (x1 == floor(x1));
    x2 = floor(x2) - (x2 == floor(x2));
    cout << (long long)(x2 - x1 + 1);
}
