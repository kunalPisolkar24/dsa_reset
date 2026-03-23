#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>> &grid, int r, int c,
                                int newColor) {

    int n = grid.size(), m = grid[0].size();
    int required = grid[r][c];

    function<void(int, int)> sol = [&](int i, int j) -> void {
      if (i < 0 or j < 0 or i >= n or j >= m or grid[i][j] != required)
        return;
      grid[i][j] = newColor;
      sol(i + 1, j);
      sol(i - 1, j);
      sol(i, j + 1);
      sol(i, j - 1);
    };
    sol(r, c);
    return grid;
  }
};
