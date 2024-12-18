#include <bits/stdc++.h>
using namespace std;

vector<int> reg, inst;

vector<int> exec(int n = inst.size()) {
    vector<int> result;
    for (int i = 0; i + 1 < n; i += 2) {
        int op = inst[i], lop = inst[i + 1],
            cop = (lop > 3 ? reg[lop - 4] : lop);
        assert(i % 2 == 0);
        switch (op) {
        case 0: reg[0] /= (1 << cop); break;
        case 1: reg[1] ^= lop; break;
        case 2: reg[1] = cop % 8; break;
        case 3:
            if (reg[0]) i = lop - 2;
            break;
        case 4: reg[1] ^= reg[2]; break;
        case 5: result.push_back(cop % 8); break;
        case 6: reg[1] = reg[0] / (1 << cop); break;
        case 7: reg[2] = reg[0] / (1 << cop); break;
        }
    }
    return result;
}

void backtrack(int i, int64_t x) {
    if (i < 0) {
        cout << x;
        exit(0);
    }
    for (int j = 0; j < 8; j++) {
        reg[0] = x * 8 + j;
        if (inst[i] == exec(inst.size() - 2)[0]) {
            backtrack(i - 1, x * 8 + j);
        }
    }
}

int main() {
    string s, t;
    while (getline(cin, s)) {
        replace(s.begin(), s.end(), ',', ' ');
        istringstream iss(s);
        while (iss >> s) {
            if (isdigit(s[0])) {
                if (reg.size() < 3) {
                    reg.push_back(stoi(s));
                } else {
                    inst.push_back(stoi(s));
                }
            }
        }
    }
    for (int x : exec()) cout << x << ",";
    cout << "\b \n";
    backtrack(inst.size() - 1, 0);
}
