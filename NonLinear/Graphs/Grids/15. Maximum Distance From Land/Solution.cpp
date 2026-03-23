#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxDistance(vector<vector<int>> &grid) {
    int mx = numeric_limits<int>::min();
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          q.push({i, j});
          dist[i][j] = 0;
        }
      }
    }

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        bool bounds = nx >= 0 and ny >= 0 and nx < n and ny < m;
        if (bounds) {
          if (dist[nx][ny] == -1) {
            dist[nx][ny] = 1 + dist[x][y];
            q.push({nx, ny});
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mx = max(mx, dist[i][j]);
      }
    }
    return mx;
  }
};
