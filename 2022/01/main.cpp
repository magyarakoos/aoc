#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> v;
    ifstream f("input.txt");
    string s;
    while (getline(f, s)) {
        if (s.empty()) {
            v.push_back(n);
            n = 0;
        }
        else {
            n += stoi(s);
        }
    }
    if (n != 0) v.push_back(n);
    sort(v.begin(), v.end(), greater<int>());
    cout << v[0] << "\n" << v[0]+v[1]+v[2] << endl;
}


