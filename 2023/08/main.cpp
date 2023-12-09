#include <bits/stdc++.h>
using namespace std;

map<string, pair<string, string>> graph;
string inst;

int wander(const string& curr, int i = 0) {
    if (curr[2] == 'Z') return 0;
    if (inst[i % inst.size()] == 'L') {
        return 1 + wander(graph[curr].first, i + 1);
    } else {
        return 1 + wander(graph[curr].second, i + 1);
    }
}

bool is_prime(int n) {
    if(n < 2) return 0;
    if (n < 4) return 1; 
    int range = sqrt(n);
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i <= range; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; 
        }
    }
    return true;
}

vector<int> pfr(int n) {
    int og = n;
    vector<int> result(n + 1, 0);
    while (n % 2 == 0) {
        result[2]++;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            result[i]++;
            n /= i;
        }
        if (n > 2 && n != og) {
            result[n]++;
        }
    }
    return result;
}

long long lcm(const vector<int>& v) {
    vector<vector<int>> prime_factors(v.size());
    for (int i = 0; i < v.size(); i++) {
        prime_factors[i] = pfr(v[i]);
    }
    map<int, int> m;
    for (const auto& prime_factor : prime_factors) {
        for (int i = 1; i < prime_factor.size(); i++) {
            if (prime_factor[i]) {
                m[i] = (m[i] ? 
                    min(m[i], prime_factor[i]) :
                    prime_factor[i]
                );
            }
        }
    }
    long long result = 1;
    for (const auto& entry : m) {
        result *= pow(entry.first, entry.second);
    }
    return result;
}

int main() {
    ifstream f("input");
    string curr, left, right; 
    vector<string> v;
    f >> inst;
    while (f >> curr >> left >> left >> right) {
        graph[curr].first = left.substr(1, 3);
        graph[curr].second = right.substr(0, 3);
        if (curr[2] == 'A') {
            v.push_back(curr);
        }
    }
    vector<int> lengths(v.size()); 
    for (int i = 0; i < v.size(); i++) {
        lengths[i] = wander(v[i]);
    }
    cout << lcm(lengths);
}
