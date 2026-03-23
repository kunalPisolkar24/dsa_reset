#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int infectionSpread(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    int healthy = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1)
          healthy++;
        if (grid[i][j] == 2) {
          dist[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool bound = nx >= 0 and ny >= 0 and nx < n and ny < m;
        if (bound) {
          if (dist[nx][ny] == -1 and grid[nx][ny] == 1) {
            dist[nx][ny] = 1 + dist[x][y];
            q.push({nx, ny});
          }
        }
      }
    }

    int mx = numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          if (dist[i][j] == -1)
            return -1;
          else
            mx = max(mx, dist[i][j]);
        }
      }
    }
    return mx;
  }
};
