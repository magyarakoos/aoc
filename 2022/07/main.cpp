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
            
        }
    }
}