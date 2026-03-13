#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    int count = 0;
    int n = grid.size(), m = grid[0].size();

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    auto bfs = [&](int row, int col) -> int {
      int totalPerimter = 0;
      queue<pair<int, int>> q;
      q.push({row, col});
      grid[row][col] = 2;

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        int currPerimeter = 4;

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          bool bounds = nx >= 0 and ny >= 0 and nx < n and ny < m;
          if (bounds) {
            if (grid[nx][ny] == 2)
              currPerimeter--;
            if (grid[nx][ny] == 1) {
              currPerimeter--;
              grid[nx][ny] = 2;
              q.push({nx, ny});
            }
          }
        }

        totalPerimter += currPerimeter;
      }
      return totalPerimter;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          count += bfs(i, j);
        }
      }
    }
    return count;
  }
};
