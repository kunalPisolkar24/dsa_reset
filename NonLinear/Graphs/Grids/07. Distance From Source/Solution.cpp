#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> distanceFromSource(vector<vector<int>> &grid, int r,
                                         int c) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    if(grid[r][c] == 1) return dist;

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    queue<pair<int, int>> q;
    q.push({r, c});
    dist[r][c] = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];
          bool bound = nx >= 0 and ny >= 0 and nx < n and ny < m;
          if (bound) {
            if (dist[nx][ny] == -1 and grid[nx][ny] != 1) {
              dist[nx][ny] = 1 + dist[x][y];
              q.push({nx, ny});
            }
          }
        }
      }
    }

    return dist;
  }
};
