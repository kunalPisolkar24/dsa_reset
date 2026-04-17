#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tiii;
typedef vector<int> vi;

class Solution {
public:
  /**
   * @brief You are given a 2D `grid` where each cell `(r, c)` has a
   * non-negative integer cost. Find the path from `(0,0)` to `(n-1, m-1)` with
   * the minimum sum of cell costs.
   *
   * @return int
   */
  int minCostGrid(const vector<vector<int>> &grid) {
    // Implementation details

    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    pq.push({grid[0][0], 0, 0});
    dist[0][0] = grid[0][0];
    vi dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    while (!pq.empty()) {
      auto [w, x, y] = pq.top();
      pq.pop();

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 and ny >= 0 and nx < n and ny < m) {
          if (dist[x][y] + grid[nx][ny] < dist[nx][ny]) {
            dist[nx][ny] = dist[x][y] + grid[nx][ny];
            pq.push({dist[nx][ny], nx, ny});
          }
        }
      }
    }
    return dist[n - 1][m - 1];
  }
};
