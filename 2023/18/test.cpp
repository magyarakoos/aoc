#include <bits/stdc++.h>
#include "lodepng.h"
using namespace std;

using u8 = unsigned char;
int mid;

void savePNG(const std::vector<std::vector<char>>& data, const char* filename) {
    size_t N = data.size();
    size_t M = data[0].size();

    vector<u8> image;

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++) {
            image.push_back(i == mid && j == mid ? 255 : data[i][j] == '#' ? 255 : 0);
            image.push_back(i == mid && j == mid ? 0 : data[i][j] == '#' ? 255 : 0);
            image.push_back(i == mid && j == mid ? 0 : data[i][j] == '#' ? 255 : 0);
            image.push_back(255);  // Alpha channel (fully opaque)
        }
    }

    // Save the image to a PNG file
    unsigned error = lodepng::encode(filename, image, M, N);

    if (error) {
        std::cerr << "Error " << error << ": " << lodepng_error_text(error) << std::endl;
    } else {
        std::cout << "Image saved successfully as " << filename << std::endl;
    }
}

void flood_fill(vector<vector<char>>& grid, int x, int y, char currC, char newC) 
{ 
    // Base cases 
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) 
        return; 
    if (grid[x][y] != currC) 
        return; 
    if (grid[x][y] == newC) 
        return; 
  
    // Replace the color at cell (x, y) 
    grid[x][y] = newC; 
  
    // Recursively call for north, east, south and west 
    flood_fill(grid, x+1, y, currC, newC); 
    flood_fill(grid, x-1, y, currC, newC); 
    flood_fill(grid, x, y+1, currC, newC); 
    flood_fill(grid, x, y-1, currC, newC); 
} 

vector<vector<char>> load() {
    fstream f("input");
    string s, hex;
    char c;
    vector<array<char, 2>> insts;

    while (f >> c >> s >> hex) {
        insts.push_back({c, (char)stoi(s)});
    }

    int i = insts.size(), j = i, w = i * 2 + 1;
    mid = i;

    vector<vector<char>> grid(w, vector<char>(w, '.'));

    grid[i][j] = '#';

    for (auto& inst : insts) {
        if (inst[0] == 'U') {
            while (inst[1]--) {
                i--;
                grid[i][j] = '#';
            }
        }
        if (inst[0] == 'D') {
            while (inst[1]--) {
                i++;
                grid[i][j] = '#';
            }
        }
        if (inst[0] == 'L') {
            while (inst[1]--) {
                j--;
                grid[i][j] = '#';
            }
        }
        if (inst[0] == 'R') {
            while (inst[1]--) {
                j++;
                grid[i][j] = '#';
            }
        }
    }
    return grid;
}

int main() {
    vector<vector<char>> v = load();
    flood_fill(v, mid + 1, mid + 1, '.', '#');
    savePNG(v, "image.png");
}