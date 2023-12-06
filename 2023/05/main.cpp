#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
int main() {
    ifstream f("input");
    string s;
    vector<u32> seeds;
    array<vector<array<u32, 3>>, 7> vals;
    const array<string, 7> br {
        "seed-to-soil",
        "soil-to-fertilizer",
        "fertilizer-to-water",
        "water-to-light",
        "light-to-temperature",
        "temperature-to-humidity",
        "humidity-to-location"
    };
    f >> s;
    while ((f >> s) && s != "seed-to-soil") {
        seeds.push_back(stol(s));
    }
    for (char i = 0; i < 7; i++) {
        f >> s; 
        vector<u32> l(3);
        for (u32 j = 0 ;; j++) {
            if (j && j % 3 == 0) {
                vals[i].push_back({l[0], l[1], l[2]});
            }
            if (!(f >> s) || s == br[i + 1]) break;
            l[j % 3] = stol(s);
        }
    }
    u32 p1 = UINT_MAX;
    for (u32 seed : seeds) {
        u32 curr = seed;
        for (const auto& val : vals) {
            for (int i = 0; i < val.size(); i++) {
                if (curr >= val[i][1] && curr <= val[i][1] + val[i][2]) {
                    curr = val[i][0] + (curr - val[i][1]);
                    i = val.size();
                }
            }
        }
        p1 = min(p1, curr);
    }
    cout << p1;
}