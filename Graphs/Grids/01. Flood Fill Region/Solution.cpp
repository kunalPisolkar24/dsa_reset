#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &grid, int r, int c,
                                int newColor) {

    int n = grid.size(), m = grid[0].size();
    int required = grid[r][c];

    if (required == newColor)
      return grid;

    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    queue<pair<int, int>> q;
    q.push({r, c});
    grid[r][c] = newColor;

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
            grid[nx][ny] == required) {
          grid[nx][ny] = newColor;
          q.push({nx, ny});
        }
      }
    }

    return grid;
  }
};