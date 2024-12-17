#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> reg, inst;
int ip;
int32_t main() {
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
    int i = 0;
    while (1) {
        i++;
        if (ip + 1 >= inst.size()) break;
        int op = inst[ip], opl = inst[ip + 1],
            opc = (opl > 3 ? reg[opl - 4] : opl);
        switch (op) {
        case 0: reg[0] /= (1 << opc); break;
        case 1: reg[1] ^= opl; break;
        case 2: reg[1] = opc % 8;
        case 3:
            if (reg[0]) ip = opl;
            break;
        case 4: reg[1] ^= reg[0]; break;
        case 5:
            if (!t.empty()) t += ",";
            t += to_string(opc % 8);
            break;
        case 6: reg[1] = reg[0] / (1 << opc); break;
        case 7: reg[2] = reg[0] / (1 << opc); break;
        }
        if (!reg[0] || op != 3) ip += 2;
    }
    cout << t;
}
