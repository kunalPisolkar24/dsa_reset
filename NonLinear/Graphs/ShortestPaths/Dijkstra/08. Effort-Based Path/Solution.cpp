#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tiii;
typedef vector<int> vi;

class Solution {
public:
  /**
   * @brief In a 2D grid, the 'effort' of a path is the MAXIMUM absolute
   * difference in height between any two consecutive cells. Find a path from
   * top-left to bottom-right that minimizes this maximum effort.
   *
   * @return int
   */
  int minimumEffort(const vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vi> dist(n, vi(m, INT_MAX));

    vi dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
      auto [w, x, y] = pq.top();
      pq.pop();

      if (w > dist[x][y])
        continue;
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx >= 0 and ny >= 0 and nx < n and ny < m) {
          int currEff = w;
          int newEff = max(currEff, abs(grid[x][y] - grid[nx][ny]));
          if (newEff < dist[nx][ny]) {
            dist[nx][ny] = newEff;
            pq.push({newEff, nx, ny});
          }
        }
      }
    }
    return dist[n - 1][m - 1];
  }
};
