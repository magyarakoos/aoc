#include <bits/stdc++.h>
using namespace std;

using point = array<int, 2>;

const vector<point> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> grid;
vector<vector<int>> costs;
array<point, 3> dirs;
int N, M;

int main() {
    fstream f("input");
    string s;

    while (f >> s) {
        vector<int> v;
        for (char c : s) {
            v.push_back(c - '0');
        }
        grid.push_back(v);
    }

    N = grid.size(), M = grid[0].size();
    costs.resize(N, vector<int>(M));

    cout << "WIP";
}
