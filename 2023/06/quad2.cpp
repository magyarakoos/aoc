#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main() {
    ifstream f("input");
    string r, s;
    f >> r; getline(f, r);
    f >> s; getline(f, s);
    long long t = stoll(
        istringstream(r | std::views::)
    );
}
