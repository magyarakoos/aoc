#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    vector<int> v;
    ifstream f("input");
    string s;
    while (getline(f, s)) {
        if (s.size()) {
            n += stoi(s);
        } else {
            v.push_back(n);
            n = 0;
        }
    }
    if (n) v.push_back(n);
    sort(v.begin(), v.end(), greater<int>());
    cout << v[0] << "\n" << v[0] + v[1] + v[2];
}
