#include <bits/stdc++.h>
using namespace std;

vector<int> tokenize(string& s) {
    for (char& c : s) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }
    istringstream iss(s);
    vector<int> v;
    int x;
    while (iss >> x) v.push_back(x);
    return v;
}
int main() {
    ifstream f("input");
    string s, t;
    while (f >> s >> t) {
        vector<int> sv = tokenize(s), tv = tokenize(t);
        if (sv)
    }
}