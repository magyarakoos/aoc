#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream f("input");
    string s;
    getline(f, s); // $ cd /
    
    vector<string> dirS;
    map<string, int> sizeS;

    while (getline(f, s)) {
        istringstream iss(s);
        vector<string> tokenS;
        while (iss >> s) {
            tokenS.push_back(s);
        }
        if (tokenS[0] == "$") {
            if (tokenS[1] == "ls") continue;
            if (tokenS[2] == "..") dirS.pop_back();
            else dirS.push_back(tokenS[2]);
        } else if (tokenS[0][0] <= '9') {
            for (const string& dir : dirS) {
                sizeS[dir] += stoi(tokenS[0]);
            }
        }
    }

    int p1 = 0, p2 = 0;

    for (const auto& [k, v] : sizeS) {
        p1 += v * (v <= 100'000);
        cout << k << ' ' << v << '\n';
    }

    cout << p1 << '\n' << p2;
}