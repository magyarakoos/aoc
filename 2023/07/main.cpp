#include <bits/stdc++.h>
using namespace std;

#define cont(v, x) (find(v.begin(), v.end(), x) != v.end())
#define _10b 0x2540BE400

map<char, char> valC {
    {'2', 1}, {'3', 2}, {'4', 3},
    {'5', 4}, {'6', 5}, {'7', 6},
    {'8', 7}, {'9', 8}, {'T', 9},
    {'J', 10},{'Q', 11},{'K', 12},
    {'A', 13}
};

bool two_pair(const vector<char>& m) {
    for (char i = 0; i < m.size(); i++) {
        for (char j = i + 1; j < m.size(); j++) {
            if (m[i] == 2 && m[j] == 2) {
                return 1;
            }
        }
    }
    return 0;
}

long strength(const pair<string, int>& hand) {
    long result = 0;
    for (char i = 4; i >= 0; i--) {
        result += valC[hand.first[i]] * pow(100, 4 - i); 
    }
    vector<char> m(13);
    for (const char c : hand.first) m[valC[c] - 1]++;
    if (cont(m, 5)) return 7 * _10b + result;
    if (cont(m, 4)) return 6 * _10b + result;
    if (cont(m, 3)) {
        if (cont(m, 2)) return 5 * _10b + result; // full
        return 4 * _10b + result;
    }
    if (two_pair(m)) return 3 * _10b + result;
    if (cont(m, 2)) return 2 * _10b + result;
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
    int p1 = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        p1 += v[i].second * (i + 1);
    }
    cout << p1;
}
