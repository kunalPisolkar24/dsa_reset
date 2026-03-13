#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> removeBoundaryIslands(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    auto bfs = [&](int row, int col) -> void {
      queue<pair<int, int>> q;
      q.push({row, col});
      grid[row][col] = 0;

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          bool bounds = nx >= 0 and ny >= 0 and nx < n and ny < m;
          if (bounds) {
            if (grid[nx][ny] == 1) {
              grid[nx][ny] = 0;
              q.push({nx, ny});
            }
          }
        }
      }
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
          if (grid[i][j]) {
            bfs(i, j);
          }
        }
      }
    }
    return grid;
  }
};
