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
        string s2 = s, t2 = t;
        for (int i = 0; i < 4; i++) {
            s2 += "?" + s;
            t2 += "," + t;
        }
        replace(t2.begin(), t2.end(), ',', ' ');
        istringstream iss(t2);
        vector<int> v;
        while (iss >> t2) v.push_back(stoi(t2));
    }
}