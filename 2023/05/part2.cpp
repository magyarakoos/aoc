#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using range = pair<ll, ll>;

vector<range> seeds;
vector<vector<pair<range, ll>>> converts(7);

void read() {
    ifstream f("input");
    string s;
    f >> s;
    for (int i = 0; (f >> s) && isdigit(s[0]); i++) {
        if (i % 2) {
            seeds.back().second = stoll(s);
        } else {
            seeds.push_back({stoll(s), 0});
        }
    }
    for (char i = 0; i < 7; i++) {
        f >> s;
        vector<ll> line(3);
        for (ll j = 0 ;; j++) {
            if (j && !(j % 3)) {
                converts[i].push_back({
                    {line[1], line[2]},
                    line[0] - line[1]
                });
            }
            if (!(f >> s) || !isdigit(s[0])) break;
            line[j % 3] = stoll(s);
        }
        sort(converts[i].begin(), converts[i].end(), 
        [](const pair<range, ll>& a, const pair<range, ll>& b){
            return a.first.first < b.first.first;
        }); 
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
        for (const pair<range, ll>& cnv : converts[i]) {
            cout << "  [(" << cnv.first.first << ','
                 << cnv.first.second << ") -> "
                 << cnv.second << "]\n";
        }
    }
    cout << '\n';
}

vector<range> map_layer(const range& rang, int i) {
    if (rang.first + rang.second > converts[i].back()
        .first.first + converts[i].back().first.second
        ) {
        return {rang};
    }
    vector<range> ranges;
    if (rang.first < converts[i][0].first.first) {
        ranges.push_back({
            rang.first, 
            converts[i][0].first.first - rang.first
        });
    }
    for (const pair<range, ll>& p : converts[i]) {
        if (max(rang.first + rang.second, p.first.first + p.first.second) -
            min(rang.first, p.first.first) < rang.second + p.first.second) {
            ranges.push_back({
                max(p.first.first, rang.first) + p.second, 
                min(p.first.second, rang.second)
            });
        }
    }
    ll last_size = 
        converts[i].back().first.first + 
        converts[i].back().first.second;
    if (last_size < rang.first + rang.second) {
        ranges.push_back({
            last_size + 1,
            rang.second - (last_size + 1)
        });
    }
    return ranges;
}

vector<range> map_range(const range& rang) {
    vector<range> result = map_layer(rang, 0);
    for (char i = 1; i < 7; i++) {
        vector<range> curr;
        for (const range& rrang : result) {
            for (range rres : map_layer(rrang, i)) {
                curr.push_back(rres);
            }
        }
        result = curr;
    }
    return result;
}

int main() {
    read();
    diagnostics();
    ll p2 = LLONG_MAX;
    vector<range> results;
    for (const range& seed : seeds) {
        for (const range& r : map_range(seed)) {
            results.push_back(r);
        }
    }
    sort(results.begin(), results.end(), [](const range& a, const range& b){
        return a.first < b.first;
    });
    for (const range& r : results) {
        cout << r.first << ' ' << r.second;
        cout << '\n';
    }
}