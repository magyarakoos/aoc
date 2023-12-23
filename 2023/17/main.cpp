#include <bits/stdc++.h>
using namespace std;

using point = array<int, 2>;
using props = array<int, 6>;

const vector<point> moves{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<vector<int>> grid;
vector<vector<int>> costs;
int N, M;

#define contains(m, e) m.count(e)

int dijkstra() {
    priority_queue<props, vector<props>, greater<props>> pq;
    map<props, int> dists;

    // start pozíció
    pq.push({0, 0, 0, 0, 0, 0});

    while (!pq.empty()) {
        props curr = pq.top(); pq.pop();
        int len = curr[0], straight = curr[1];
        point pos{curr[2], curr[3]}, dir{curr[4], curr[5]};
        cout << pq.size() << '\n';

        if (pos[0] == N - 1 && pos[1] == M - 1) return dists[curr];

        for (const point move : moves) {
            // ellentétes irány, visszamenni mindig felesleges
            if (-dir[0] == move[0] && -dir[1] == move[1])
                continue;

            int new_straight;

            if (dir[0] == move[0] && dir[1] == move[1]) {
                // azonos irány, meg kell növelni
                new_straight = straight + 1;
            } else {
                // új irány, hossza 1
                new_straight = 1;
            }

            // nem lehetséges, hosszabb az egyenes mint 3 
            if (new_straight > 3) continue;

            // új pozíció, adott irányba elmozdítjuk
            point new_pos{pos[0] + move[0], pos[1] + move[1]};

            // kiment a pályáról
            if (new_pos[0] < 0 || new_pos[1] < 0 || new_pos[0] >= N || new_pos[1] >= M)
                continue;
            
            int heat_loss = grid[new_pos[0]][new_pos[1]];

            // a mező új lehetséges tulajdonságai, vagy jobb mint az eddigi vagy nem
            props new_props {
                dists[curr] + heat_loss,
                new_straight, 
                new_pos[0], new_pos[1],
                move[0], move[1]
            };

            // ez eddig a legjobb, a mapen beállítjuk és megy a heapre is
            if (dists[new_props] == 0 || new_props[0] < dists[new_props]) {
                dists[new_props] = new_props[0];
                pq.push(new_props);
            }
        }
    }
    // hibás input
    return false;
}

int main() {
    fstream f("input");
    string s;

    while (f >> s) {
        vector<int> v;
        for (char c : s) {
            v.push_back(c - '0');
        }
        grid.push_back(v);
    }

    N = grid.size(), M = grid[0].size();
    costs.resize(N, vector<int>(M));

    cout << dijkstra() << '\n';
}
