#include <bits/stdc++.h>
using namespace std;

void replace(string& s) {

}
int main() {
    ifstream f("input");
    string s, t;
    while (f >> s >> t) {
        for (char& c : s) {
            if (c == '[' || c == ']' || c == ',') {
                c = ' ';
            }
        }
        for (char& c : t) {
            if (c == '[' || c == ']' || c == ',') {
                c = ' ';
            }
        }
        
    }
}