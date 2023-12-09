#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, string>> graph;
string inst;

int wander(const string& curr, int i = 0) {
    if (curr == "ZZZ") return 0;
    if (i == inst.size()) i = 0;
    if (inst[i] == 'L') {
        return 1 + wander(graph[curr].first, i + 1);
    } else {
        return 1 + wander(graph[curr].second, i + 1);
    }
}

int main() {
    ifstream f("input");
    string curr, left, right;
    f >> inst;
    while (f >> curr >> left >> left >> right) {
        graph[curr].first = left.substr(1, 3);
        graph[curr].second = right.substr(0, 3);
    }
    cout << wander("AAA");
}