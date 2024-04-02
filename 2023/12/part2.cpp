#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

ll solve(string s, vector<int> v) {

    s += ".";
    v.push_back(0);

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
    for (int k = 0; k <= v[j]; k++) {

        int dot_count = 0, hash_count = 0;
        
        if (k) {
            hash_count += dp[i - 1][j][k - 1];
        } else {
            if (j) {
                dot_count += dp[i - 1][j - 1][v[j - 1]];
                dot_count += dp[i - 1][j - 1][0];
            } else {
                dot_count += s.substr(0, i + 1).find('#') == s.npos;
            }
        }

        if (s[i] == '#' || s[i] == '?') {
            dp[i][j][k] += hash_count;
        }
        if (s[i] == '.' || s[i] == '?') {
            dp[i][j][k] += dot_count;
        }

        cout << i << " " << j << " " << k << " | " << dot_count << " " << hash_count << "\n";
    }}}

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k <= v[j]; k++) {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return dp.back().back().front();
}

int main() {
    /*ifstream f("input");
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
    cout << p2;*/
    ifstream f("input");
    string s, t;
    ll p2 = 0;
    while (f >> s >> t) {
        replace(t.begin(), t.end(), ',', ' ');
        istringstream iss(t);
        vector<int> v;
        while (iss >> t) v.push_back(stoi(t));
        p2 += solve(s, v);
    }
    cout << p2;
}