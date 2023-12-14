#include <bits/stdc++.h>
using namespace std;

#define PART 2

void transpose(vector<string>& v) {
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

bool valid(const vector<string>& table, int i) {
    int b = i - 1, t = i, result = 0;
    while (true) {
        for (int p = 0; p < table[0].size(); p++) {
            result += (table[b][p] != table[t][p]);
        }
        if (b > 0 && t < table.size() - 1) {
            b--;
            t++;
        } else return result == (PART == 1 ? 0 : 1);
    }
    return 0;
}

int main() {
    fstream f("input");
    vector<vector<string>> tables{{}};
    string s;
    while (getline(f, s)) {
        if (s.empty()) {
            tables.push_back({});
        } else {
            tables.back().push_back(s);
        }
    }
    int p1 = 0;
    for (vector<string>& table : tables) {
        for (int i = 1; i < table.size(); i++) {
            if (valid(table, i)) {
                p1 += i * 100;
            }
        }
        transpose(table);
        for (int i = 1; i < table.size(); i++) {
            if (valid(table, i)) {
                p1 += i;
            }
        }
    }
    cout << p1;
}