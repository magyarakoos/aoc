#include <bits/stdc++.h>
using namespace std;

void flood_fill(vector<vector<char>>& grid, int x, int y, char currC, char newC) {
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size() || grid[x][y] != currC || grid[x][y] == newC) 
        return; 
    grid[x][y] = newC; 
    flood_fill(grid, x+1, y, currC, newC); 
    flood_fill(grid, x-1, y, currC, newC); 
    flood_fill(grid, x, y+1, currC, newC); 
    flood_fill(grid, x, y-1, currC, newC); 
}

int main() {
    fstream f("input");
    string s, hex;
    char c;
    vector<array<char, 2>> insts;
    while (f >> c >> s >> hex) {
        insts.push_back({c, (char)stoi(s)});
    }
    int i = insts.size(), j = i, w = i * 2 + 1;
    vector<vector<char>> grid(w, vector<char>(w, '.'));
    grid[i][j] = '#';
    for (auto& inst : insts) {
        if (inst[0] == 'U') {
            while (inst[1]--) {
                i--;
                grid[i][j] = '#';
            }
        }
        if (inst[0] == 'D') {
            while (inst[1]--) {
                i++;
                grid[i][j] = '#';
            }
        }
        if (inst[0] == 'L') {
            while (inst[1]--) {
                j--;
                grid[i][j] = '#';
            }
        }
        if (inst[0] == 'R') {
            while (inst[1]--) {
                j++;
                grid[i][j] = '#';
            }
        }
    }
    flood_fill(grid, insts.size() + 1, insts.size() + 1, '.', '#');
    int p1 = 0;
    for (int i = 0; i < grid.size(); i++) {
        p1 += count(grid[i].begin(), grid[i].end(), '#');
    }
    cout << p1;
}
