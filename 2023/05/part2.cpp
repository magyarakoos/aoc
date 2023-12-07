#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using range = pair<ll, ll>;

vector<range> seeds;
vector<vector<pair<range, range>>> converts;

void read() {
    ifstream f("input");
    string s;
    f >> s;
    for (int i = 0; (f >> s) && isdigit(s[0]); i++) {
        if (i % 2) {
            seeds.back().second = seeds.back().first + stoll(s);
        } else {
            seeds.push_back({stoll(s), 0});
        }
    }

    converts.resize(7);
    
    for (char i = 0; i < 7; i++) {
        f >> s;
        vector<ll> line(3);
        for (ll j = 0 ;; j++) {
            if (j && !(j % 3)) {
                converts[i].push_back({
                    {line[0], line[0] + line[2]}, 
                    {line[1], line[1] + line[2]}
                });
            }
            if (!(f >> s) || !isdigit(s[0])) break;
            line[j % 3] = stoll(s);
        }
    }
}

void diagnostics() {
    cout << "SEEDS:\n";
    for (const range& seed : seeds) {
        cout << '(' << seed.first << ',' << seed.second << ")\n";
    }
    cout << '\n';

    cout << "CONVERTS:\n";
    for (char i = 0; i < 7; i++) {
        cout << "convert " << i + 1 << ":\n";
        for (const pair<range, range>& cnv : converts[i]) {
            cout << "  [(" << cnv.first.first << ','
                 << cnv.first.second << ") -> ("
                 << cnv.second.first << ','
                 << cnv.second.second << ")]\n";
        }
    }
    cout << '\n';
}

range map_range(const range& rang) {
    /// TODO: solve part 2
    throw exception();
}

int main() {
    read();
    diagnostics();

    vector<range> current = seeds;
    for (int i = 0; i < seeds.size(); i++) {
        for (const auto& convert : converts) {
            seeds[i] = map_range(seeds[i]);
        }
    }

    cout << min_element(seeds.begin(), seeds.end(),
        [](const range& a, const range& b) {
            return a.first < b.first;
        }
    )->first;
}