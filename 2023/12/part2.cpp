#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll solve(const string& s, const vector<int>& groupS) {

}

int main() {
    ifstream f("input");
    string s, t;
    ll p2 = 0;
    while (f >> s >> t) {
        replace(t.begin(), t.end(), ',', ' ');
        stringstream ss(t);
        int n;
        vector<int> v, w;
        while (ss >> n) v.push_back(n);
        for (int i = 0; i < 5;)
        p2 += solve(s, {});
    }
}