#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int shortestPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    if (grid[0][0] == 1)
      return -1;

    vector<vector<int>> dist(n, vector<int>(m, -1));

    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          bool bounds = nx >= 0 and ny >= 0 and nx < n and ny < m;
          if (bounds) {
            if (dist[nx][ny] == -1 and grid[nx][ny] != 1) {
              dist[nx][ny] = dist[x][y] + 1;
              q.push({nx, ny});
            }
          }
        }
      }
    }

    return dist[n - 1][m - 1];
  }
};
