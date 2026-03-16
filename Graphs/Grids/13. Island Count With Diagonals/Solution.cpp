#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countIslandsDiagonals(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int total = 0;

    vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1}, 
    dy{1, 1, 0, -1, -1, -1, 0, 1};

    auto bfs = [&](int row, int col) -> int {

      queue<pair<int, int>> q;
      q.push({row, col});
      grid[row][col] = 2;

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          bool bounds = nx >= 0 and ny >= 0 and nx < n and ny < m;
          if (bounds) {
            if (grid[nx][ny] == 1) {
              q.push({nx, ny});
              grid[nx][ny] = 2;
            }
          }
        }
      }
      return 1;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          total += bfs(i, j);
        }
      }
    }
    return total;
  }
};
