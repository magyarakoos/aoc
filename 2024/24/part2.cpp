#include <bits/stdc++.h>
using namespace std;

const int MAXN = 44;

map<string, vector<pair<string, int>>> g;
vector<string> edgeS;

string add_number(int i, string s) {
    ostringstream oss;
    oss << s << setw(2) << setfill('0') << i;
    return oss.str();
}

int p = -1;
string gen_label() {
    p++;
    return format("{}{}{}", char('a' + p / (26 * 26) % 26),
                  char('a' + p / 26 % 26),
                  char('a' + p % 26));
}

map<int, string> cache;
string f(int i) {
    if (cache.count(i)) return cache[i];

    string x = add_number(i, "x");
    string y = add_number(i, "y");
    string z = add_number(i, "z");

    if (i == 0) {
        edgeS.push_back(format("{} XOR {} -> {}", x, y, z));
        string c0 = gen_label();
        edgeS.push_back(
            format("{} AND {} -> {}", x, y, c0));
        return c0;
    }

    string c0 = f(i - 1);
    string s1 = gen_label();
    edgeS.push_back(format("{} XOR {} -> {}", x, y, s1));
    edgeS.push_back(format("{} XOR {} -> {}", c0, s1, z));

    string c01 = gen_label();
    edgeS.push_back(format("{} AND {} -> {}", c0, s1, c01));
    string c10 = gen_label();
    edgeS.push_back(format("{} AND {} -> {}", x, y, c10));
    string c1 = gen_label();
    edgeS.push_back(format("{} OR {} -> {}", c01, c10, c1));

    return c1;
}

int main() {
    f(MAXN);
    ofstream fout("input.1");
    for (string s : edgeS) fout << s << "\n";
}
