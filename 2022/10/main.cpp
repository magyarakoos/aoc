#include <bits/stdc++.h>

using namespace std;

vector<string> read(const string& path) {
    vector<string> v;
    ifstream in(path);
    string s;

    while (getline(in, s)) {
        if (s.size() > 0) {
            v.push_back(s);
        }
    }
    return v;
}

void part1(const vector<string>& input) {
    int x = 1;
    int cyc = 0;
    int result = 0;

    for (auto& l : input) {
        cyc++;

        if ((cyc - 20) % 40 == 0) {
            result += cyc * x;
        }
        if (l != "noop") {
            cyc++;
            if ((cyc - 20) % 40 == 0) {
                result += cyc * x;
            }
            x += stoi(l.substr(5));
        }
    }

    cout << result << "\n";
}

void draw(int& cyc, int& x) {
    if (abs((cyc - 1) % 40 - x) <= (3/2)) {
        cout << "█";
    }
    else {
        cout << " ";
    }
    if (cyc % 40 == 0) {
        cout << "\n";
    }
}

void part2(const vector<string>& input) {
    int x = 1;
    int cyc = 0;

    for (auto& l : input) {
        cyc++;
        draw(cyc, x);

        if (l != "noop") {
            cyc++;
            draw(cyc, x);
            x += stoi(l.substr(5));
        }
    }
}

int main() {
    vector<string> input = read("input.txt");

    part1(input);
    part2(input);
}
