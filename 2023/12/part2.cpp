#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(const string& s, const vector<int>& v) {

    int N = s.size(), 
        M = v.size(), 
        O = *max_element(v.begin(), v.end());

    // dp[i][j][k] = hányféleképpen lehet elrendezni
    // a [0..i) tartományát a stringnek, 
    // az első j-1 csoport teljes lefedésével,
    // amennyiben ez a j. csoport k. eleme
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

        ll dot_count = 0, hash_count = 0;
        
        // hash csak akkor lehet, ha a jelenlegi szakasznak legalább az első eleme
        if (k) {
            hash_count += dp[i - 1][j][k - 1];
        } else {
            // dot nem lehet része szakasznak, így csak akkor pozitív az értéke ha k = 0
            if (j) {
                // amennyiben ez nem a legelső csoport, dot lehet ott
                dot_count += dp[i - 1][j][0];
                dot_count += dp[i - 1][j - 1][v[j - 1]];
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
    }}}

    return dp.back().back().front();
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
        v.push_back(0);
        p2 += solve(s2 + ".", v);
    }
    cout << p2;
}