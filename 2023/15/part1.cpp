#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f("input");
    string s;
    f >> s;
    replace(s.begin(), s.end(), ',', ' ');
    stringstream ss(s);
    int p1 = 0;
    while (ss >> s) {
        int sum = 0;
        for (char c : s) {
            sum += c;
            sum *= 17;
            sum %= 256;
        }
        p1 += sum;
    }
    cout << p1;
}
