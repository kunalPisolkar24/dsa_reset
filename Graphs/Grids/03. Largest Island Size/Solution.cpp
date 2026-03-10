#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestIsland(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int mxArea = numeric_limits<int>::min();
    function<int(int,int)> dfs = [&](int i, int j) -> int {
        int count = 1;
        if(i < 0 or j < 0 or i >= n or j >= m or grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        count += dfs(i - 1, j);
        count += dfs(i + 1, j);
        count += dfs(i, j - 1);
        count += dfs(i, j + 1);
        return count;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j]) {
          int area = dfs(i, j);
          mxArea = max(mxArea, area);
        }
      }
    }
    return mxArea;
  }
};
