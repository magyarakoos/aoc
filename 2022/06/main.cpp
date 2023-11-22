#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream f("input");
    string s;
    f >> s;
    deque<char> ms({s[0], s[1], s[2]});
    for (int i = 3; i < s.size(); i++) {
        ms.push_back(s[i]);
        // TODO: rape sebi
        ms.pop_front();
    }
}