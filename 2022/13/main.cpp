#include <bits/stdc++.h>
using namespace std;

vector<int> tokenize(string& s) {
    for (char& c : s) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }
    
}
int main() {
    ifstream f("input");
    string s, t;
    while (f >> s >> t) {
        replace(s);
        replace(t);
        istringstream iss(s), itt(t);
        vector<int> sv, tv;

    }
}