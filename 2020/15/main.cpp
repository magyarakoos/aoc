#include <bits/stdc++.h>
using namespace std;

struct CircularBuffer {
    int arr[2];
    int front = 0;
    int size = 0;
    void push_back(int val) {
        if (size < 2) {
            arr[(front + size) % 2] = val;
            size++;
        } else {
            arr[front] = val;
            front = (front + 1) % 2;
        }
    }
    int back() const {
        return arr[((front + size - 1 + 2) % 2)];
    }
    int front_val() const { return arr[front]; }
};

const int TURNS = 3e7;
vector<CircularBuffer> m(TURNS + 1);

int main() {
    int x = 0, n = 1;
    for (int i = 1; cin >> x; i++, n++) {
        m[x].push_back(i);
    }
    for (int i = n; i <= TURNS; i++) {
        x = (m[x].size ? m[x].back() - m[x].front_val()
                       : 0);
        m[x].push_back(i);
    }
    cout << x << endl;
}
