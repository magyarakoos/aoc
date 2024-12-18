#include <bits/stdc++.h>
using namespace std;

vector<int> exec(vector<int>& reg, vector<int> inst) {
    vector<int> result;
    for (int i = 0; i + 1 < inst.size(); i += 2) {
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

int main() {
    vector<int> reg, inst;
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
    for (int x : exec(reg, inst)) cout << x << ",";
    cout << "\b \n";
    vector<int> result;
    for (int i = 0; i < inst.size(); i++) {
        for (int A = 0; A <= 1024; A++) {
            reg[0] = A;
            if (exec(reg, vector<int>(inst.begin(),
                                      inst.end() - 2))[0] ==
                inst[i]) {
                cout << inst[i] << " " << A << "\n";
                result.push_back(A);
                break;
            }
        }
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
}
