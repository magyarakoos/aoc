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

int main() {
    fstream f("input");
    string s;
    while (f >> s) v.push_back(s);
    set<int> values;
    for (int i = 0; i < (int)1e9; i++) {
        north();
        west();
        south();
        east();
        if (((int)1e9 - (i + 1)) % 72 == 0) {
            int result = 0;
            for (int i = 0; i < v.size(); i++) {
                result += (v.size() - i) * count(v[i].begin(), v[i].end(), 'O');
            }
            if (values.find(result) != values.end()) {
                cout << result;
                return 0;
            }
            values.insert(result);
        }
    }
}
