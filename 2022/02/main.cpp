#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream f("input");
    char a, b;
    int p1 = 0, p2 = 0;
    while (f >> a >> b) {
        if (a == 'A') {
            if (b == 'X') { p1 += 4; p2 += 3; }
            else if (b == 'Y') { p1 += 8; p2 += 4; }
            else { p1 += 3; p2 += 8; }
        } else if (a == 'B') {
            if (b == 'X') { p1 += 1; p2 += 1; }
            else if (b == 'Y') { p1 += 5; p2 += 5; }
            else { p1 += 9; p2 += 9; }
        } else {
            if (b == 'X') { p1 += 7; p2 += 2; }
            else if (b == 'Y') { p1 += 2; p2 += 6; }
            else { p1 += 6; p2 += 7; }
        }
    }
    cout << p1 << '\n' << p2;
}
