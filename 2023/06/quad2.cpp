#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> r; getline(f, r);
    f >> s; getline(f, s);
    r.erase(remove_if(r.begin(), r.end(), ::isspace), r.end());
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    long long d = stoll(r), t = stoll(s);
    double
        x1 = (t - sqrt(t * t - 4 * d)) / 2,
        x2 = (t + sqrt(t * t - 4 * d)) / 2;
    cout << floor(x2) - (x2 == floor(x2)) - (ceil(x1)  + (x1 == floor(x1))) + 1;
}
