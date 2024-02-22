#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

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
        } else {
            if ()
        }
    }
}