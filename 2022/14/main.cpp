#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;

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

    int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;

    for (const auto& worm : v) {
        for (auto [x, y] : worm) {
            minx = min(minx, x);
            maxx = max(maxx, x);
            miny = min(miny, y);
            maxy = max(maxy, y);
        }
    }
}