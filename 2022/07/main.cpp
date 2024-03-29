#include <bits/stdc++.h>
using namespace std;

int id, root;
int main() {
    ifstream f("input");
    string s;
    getline(f, s);
    
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
            else dirS.push_back(to_string(++id));
        } else if (tokenS[0][0] <= '9') {
            root += stoi(tokenS[0]);
            for (const string& dir : dirS) {
                sizeS[dir] += stoi(tokenS[0]);
            }
        }
    }

    int p1 = 0, p2 = root;

    for (const auto& [k, v] : sizeS) {
        p1 += v * (v <= 100'000);
        if (v >= root - 40'000'000) p2 = min(p2, v);
    }

    cout << p1 << '\n' << p2;
}