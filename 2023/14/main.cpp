#include <bits/stdc++.h>
using namespace std;

int main() {
    fstream f("input");
    string s;
    vector<string> v;
    while (f >> s) v.push_back(s);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == 'O') {
                int k = i;
                while (k && v[k - 1][j] == '.') {
                    k--;
                }
                swap(v[i][j], v[k][j]);
            }
        }
    }
    int p1 = 0;
    for (int i = 0; i < v.size(); i++) {
        p1 += (v.size() - i) * count(v[i].begin(), v[i].end(), 'O');
    }
    cout << p1;
}
