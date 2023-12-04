#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s, t;
    int p1 = 0;
    vector<int> vals;
    while (getline(f, s)) {
        istringstream iss(s.substr(s.find(':') + 1));
        vector<int> nums, winners;
        while ((iss >> t) && t != "|") nums.push_back(stoi(t));
        while (iss >> t) winners.push_back(stoi(t));
        int v = 0, c = 0;
        for (int n : nums) {
            if (find(winners.begin(), winners.end(), n) != winners.end()) {
                v = (!v ? 1 : v * 2);
                c++;
            }
        }
        p1 += v;
        vals.push_back(c);
    }
    vector<int> db(vals.size(), 1);
    for (int i = 0; i < db.size(); i++) {
        for (int j = i + 1; j <= i + vals[i] && j < db.size(); j++) {
            db[j] += db[i];
        }
    }
    cout << p1 << '\n' << accumulate(db.begin(), db.end(), 0);
}
