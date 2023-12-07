#include <bits/stdc++.h>
using namespace std;

#define cont(v, x) (find(v.begin(), v.end(), x) != v.end())
#define _10b 0x2540BE400

map<char, char> valC {
    {'2', 1}, {'3', 2}, {'4', 3},
    {'5', 4}, {'6', 5}, {'7', 6},
    {'8', 7}, {'9', 8}, {'T', 9},
    {'Q', 10},{'K', 11},{'A', 12},
};

bool two_pair(const vector<char>& m, int j) {
    if (j >= 2) return 1;
    if (j == 1) return cont(m, 2);
    for (char i = 0; i < m.size(); i++) {
        for (char j = i + 1; j < m.size(); j++) {
            if (m[i] == 2 && m[j] == 2) {
                return 1;
            }
        }
    }
    return 0;
}

bool full(const vector<char>& m, int j) {
    if (j >= 3) return 1;
    if (j == 2) return cont(m, 2); 
    if (j == 1) return two_pair(m, 0);
    return cont(m, 3) && cont(m, 2);
}

long strength(const pair<string, int>& hand) {
    long result = 0;
    for (char i = 4; i >= 0; i--) {
        result += valC[hand.first[i]] * pow(100, 4 - i); 
    }
    char j = 0;
    vector<char> m(12);
    for (const char c : hand.first) {
        if (c == 'J') {
            j++;
        } else {
            m[valC[c] - 1]++;
        }
    }
    if (cont(m, 5 - j)) return 7 * _10b + result;
    if (cont(m, 4 - j)) return 6 * _10b + result;
    if (full(m, j))     return 5 * _10b + result;
    if (cont(m, 3 - j)) return 4 * _10b + result;
    if (two_pair(m, j)) return 3 * _10b + result;
    if (cont(m, 2 - j)) return 2 * _10b + result;
    return result;
}

int main() {
    ifstream f("input");
    string h;
    int b;
    vector<pair<string, int>> v;
    while (f >> h >> b) v.push_back({h, b});
    sort(v.begin(), v.end(), [](
    const pair<string, int>& a, const pair<string, int>& b){
        return strength(a) < strength(b);
    });
    int p2 = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        p2 += v[i].second * (i + 1);
    }
    cout << p2;
}
