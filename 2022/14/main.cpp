#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;

int N, M;
vector<string> grid;

void drop(int x, int y) {
    if (y + 1 == N) return;
    if (grid[y + 1][x] == '.') { drop(x, y + 1); return; }
    else if (grid[y + 1][x - 1] == '.') { drop(x - 1, y + 1); return; }
    else if (grid[y + 1][x + 1] == '.') { drop(x + 1, y + 1); return; }
    grid[y][x] = 'o';
}

int main() {
    ifstream f("input");
    string s;
    vector<vector<point>> v;
    while (getline(f, s)) {
        v.push_back({});
        istringstream iss(s);
        while (iss >> s) {
            if (s == "->") continue;
            v.back().push_back({
                stoi(s.substr(0, s.find(','))),
                stoi(s.substr(s.find(',') + 1))
            });
        }
    }
    int minx = 500, maxx = 500, maxy = 0;
    for (const auto& worm : v) {
        for (auto [x, y] : worm) {
            minx = min(minx, x);
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        }
    }
    maxy++; minx--; maxx++;
    minx -= 10;
    maxx += 10;
    N = maxy + 2, M = maxx - minx + 1;
    grid.assign(N, string(M, '.'));
    for (const auto& worm : v) {
        for (size_t i = 1; i < worm.size(); i++) {
            for (int y = min(worm[i - 1][1], worm[i][1]); y <= max(worm[i - 1][1], worm[i][1]); y++) {
                for (int x = min(worm[i - 1][0], worm[i][0]); x <= max(worm[i - 1][0], worm[i][0]); x++) {
                    grid[y][x - minx] = '#';
                }
            }
        }
    }
    replace(grid.back().begin(), grid.back().end(), '.', '#');


    int p2 = 0;
    while (1) {
        cout << "\x1B[2J\x1B[H";
        for (const string& line : grid) cout << line << '\n';
        cout << grid[0][500 - minx] << '\n';
        this_thread::sleep_for(chrono::milliseconds(250));

        drop(500 - minx, 0);
        if (grid[0][500 - minx] != '0') p2++;
        else break;
    }
    cout << p2;
}