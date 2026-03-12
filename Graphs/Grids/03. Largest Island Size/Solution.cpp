#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int mxArea = numeric_limits<int>::min();

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    auto bfs = [&](int row, int col) -> int {
      int count = 0;
      queue<pair<int, int>> q;
      q.push({row, col});
      grid[row][col] = 2;

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        count++;

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] == 1) {
            grid[nx][ny] = 2;
            q.push({nx, ny});
          }
        }
      }
      return count;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          int area = bfs(i, j);
          mxArea = max(mxArea, area);
        }
      }
    }
    return mxArea;
  }
};
