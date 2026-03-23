#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countIslandsDiagonals(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int total = 0;
    function<int(int, int)> dfs = [&](int i, int j) -> int {
      if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 2 or grid[i][j] == 0)
        return 0;
      grid[i][j] = 2;

      dfs(i, j + 1);
      dfs(i + 1, j + 1);

      dfs(i + 1, j);
      dfs(i + 1, j - 1);

      dfs(i, j - 1);
      dfs(i - 1, j - 1);

      dfs(i - 1, j);
      dfs(i - 1, j + 1);
      return 1;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          total += dfs(i, j);
        }
      }
    }
    return total;
  }
};
