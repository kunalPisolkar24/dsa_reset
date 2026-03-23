#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> boundaryFloodFill(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    function<void(int, int)> dfs = [&](int i, int j) -> void {
      if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0 or
          grid[i][j] == 2)
        return;
      grid[i][j] = 2;
      dfs(i + 1, j);
      dfs(i - 1, j);
      dfs(i, j - 1);
      dfs(i, j + 1);
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 or j == 0 or i == n - 1 or j == m - 1) {
          if (grid[i][j])
            dfs(i, j);
        }
      }
    }

    return grid;
  }
};
