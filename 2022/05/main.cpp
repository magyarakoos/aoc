#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<stack<char>> stacks;
    vector<array<int, 3>> inst;
    vector<string> v;

    ifstream f("input");
    string s;
    int sep;
    
    for (int i = 0; getline(f, s); i++) {
        if (s.size() > 1 && s[1] == '1') {
            stacks.resize(s[s.size() - 2] - '0');
            sep = i;
        }
        if (!s.empty()) v.push_back(s);
    }
    for (int i = sep - 1; i >= 0; i--){
        for (int j = 1; j < v[i].size(); j += 4) {
            if (v[i][j] != ' ') stacks[(j - 1) / 4].push(v[i][j]);
        }
    }
    for (int i = sep + 1; i < v.size(); i++) {
        vector<string> vx;
        istringstream iss(v[i]);
        while (iss) {
            string w;
            iss >> w;
            vx.push_back(w);
        }
        inst.push_back({stoi(vx[1]), stoi(vx[3]) - 1, stoi(vx[5]) - 1});
    }

    vector<stack<char>> stacks2 = stacks;
    for (const array<int, 3>& a : inst) {
        stack<char> st;
        for (int i = 0; i < a[0]; i++) {
            if (stacks[a[1]].empty()) break;
            stacks[a[2]].push(stacks[a[1]].top());
            stacks[a[1]].pop();
        }
        for (int i = 0; i < a[0]; i++) {
            if (stacks2[a[1]].empty()) break;
            st.push(stacks2[a[1]].top());
            stacks2[a[1]].pop();
        }
        while (!st.empty()) {
            stacks2[a[2]].push(st.top());
            st.pop();
        }
    }
    for (const stack<char>& st : stacks) cout << st.top();
    cout << '\n';
    for (const stack<char>& st : stacks2) cout << st.top();
}
