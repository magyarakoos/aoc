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
    int p1 = 0;
    while (f >> s >> t) {
        vector<int> sv = tokenize(s), tv = tokenize(t);
        if (sv.size() < tv.size()) {
            for (int i = 0; i < sv.size(); i++) {
                if (sv)
            }
            p1++;
        }
    }
}