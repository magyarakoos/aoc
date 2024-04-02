#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll solve(const string& s, const vector<int>& v) {

    int N = s.size(), 
        M = v.size(), 
        O = *max_element(v.begin(), v.end());

    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(M, vector<ll>(O + 1)));

    if (s[0] == '#' || s[0] == '?') {
        dp[0][0][1] = 1;
    }
    if (s[0] == '.' || s[0] == '?') {
        dp[0][0][0] = 1;
    }
    
    for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
    for (int k = 0; k < O; k++) {

        
    }}}
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
        while (iss >> t) v.push_back(stoi(t));
        p2 += solve(s2, v);
    }
    cout << p2;
}