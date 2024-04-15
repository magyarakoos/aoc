f = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
vis = zeros(Int, length(f), length(f[1]))
p1 = 0; curr = 0
ψ = (i, j) -> begin
    if i < 1 || j < 1 || i > length(f) || j > length(f[1]) ||
       vis[i, j] == curr return end
    f[i][j] += 1
    if f[i][j] <= 9 return end
    vis[i, j] = curr
    global p1 += 1
    f[i][j] = 0
    for ni in (i - 1):(i + 1), nj in (j - 1):(j + 1)
        ψ(ni, nj)
    end
end
for _ in 1:100
    global curr += 1
    for i in eachindex(f), j in eachindex(f[1])
        ψ(i, j)
    end
end
println(p1)
#include <bits/stdc++.h>
using namespace std;
#define N 10
#define K 10
int board[N][N];
int flashed[N][N];
int flashedMarker = 1;
int res = 0;
void boop(int i, int j) {
    if (i < 0 || j < 0 || i >= N || j >= N || flashed[i][j] == flashedMarker) return;
    board[i][j]++;
    if (board[i][j] < K) return;
    flashed[i][j] = flashedMarker;
    res++;
    board[i][j] = 0;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            boop(i + di, j + dj);
        }
    }

}
int main() {
    ifstream f(".input.txt");
    string l;
    for (int i = 0; i < N; i++) {
        f >> l;
        for (int j = 0; j < N; j++) {
            board[i][j] = l[j] - '0';
        }
    }
    f.close();
    for (int i = 0; i < 100; i++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                boop(i, j);
            }
        }
        flashedMarker++;
    }
    cout << res;
}