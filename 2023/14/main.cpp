#include <bits/stdc++.h>
using namespace std;

vector<string> v;

void transpose() {
    int rows = v.size();
    int cols = v[0].size();
    vector<string> result(cols, string(rows, ' '));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = v[i][j];
        }
    }
    v = result;
}

void north() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == 'O') {
                int k = i;
                while (k && v[k - 1][j] == '.') {
                    k--;
                }
                swap(v[i][j], v[k][j]);
            }
        }
    }
}

void south() {
    for (int i = v.size() - 1; i >= 0; i--) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == 'O') {
                int k = i;
                while (k < v.size() - 1 && v[k + 1][j] == '.') {
                    k++;
                }
                swap(v[i][j], v[k][j]);
            }
        }
    }
}

void west() {
    transpose();
    north();
    transpose();
}

void east() {
    transpose();
    south();
    transpose();
}

void print(const vector<string>& vec) {
    for (const string& l : vec) cout << l << '\n';
    cout << '\n';
} 

int main(int argc, char* argv[]) {
    fstream f("input");
    string s;
    while (f >> s) v.push_back(s);
    int cyc = stoi(argv[1]);
    map<vector<string>, vector<int>> m;
    for (int i = 0; i < cyc; i++) {
        north();
        west();
        south();
        east();
        m[v].push_back(i);
    }
    vector<pair<int, int>> vec;
    for (const auto& entry : m) {
        /*cout << "REP [" << entry.second.size() << "]: ";
        for (int n : entry.second) {
            cout << n << ' ';
        }
        cout << '\n';*/
        vec.push_back({entry.second.front(), entry.second.size()});
    }
    sort(vec.begin(), vec.end(), [](auto a, auto b){ return a.first < b.first; });
    int nig = 0;
    for (pair<int, int>& p : vec) {
        cout << p.first << ' ' << p.second << '\n';
        if (p.second == 13) nig++;
    }
    cout << nig << '\n';
    return 0;
    int p1 = 0;
    for (int i = 0; i < v.size(); i++) {
        p1 += (v.size() - i) * count(v[i].begin(), v[i].end(), 'O');
    }
    cout << p1;
}
