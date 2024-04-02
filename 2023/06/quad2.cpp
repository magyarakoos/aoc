#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> r; getline(f, r);
    f >> s; getline(f, s);
    replace(r.begin(), r.end(), ' ', ' ');
}
