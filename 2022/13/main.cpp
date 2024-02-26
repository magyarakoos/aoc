#include <bits/stdc++.h>
using namespace std;

vector<int> tokenize(string& s) {
    for (char& c : s) {
        if (c == '[' || c == ']' || c == ',') {
            c = ' ';
        }
    }
    istringstream iss(s);
    int x;
    while (iss >> x) {

    }
}
int main() {
    ifstream f("input");
    string s, t;
    while (f >> s >> t) {
        
    }
}