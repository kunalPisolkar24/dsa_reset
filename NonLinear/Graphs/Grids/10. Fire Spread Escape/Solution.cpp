#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool fireEscape(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dist1(n, vector<int>(m, -1));
    vector<vector<int>> dist2(n, vector<int>(m, -1));
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    queue<pair<int, int>> q1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 'S') {
          if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            return true;

          queue<pair<int, int>> q;
          q.push({i, j});
          dist1[i][j] = 0;

          while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
              int nx = x + dx[k];
              int ny = y + dy[k];

              if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

              if (dist1[nx][ny] == -1 && grid[nx][ny] != '#' &&
                  grid[nx][ny] != 'F') {
                dist1[nx][ny] = dist1[x][y] + 1;
                q.push({nx, ny});
              }
            }
          }
        }

        else if (grid[i][j] == 'F') {
          q1.push({i, j});
          dist2[i][j] = 0;
        }
      }
    }

    while (!q1.empty()) {
      auto [x, y] = q1.front();
      q1.pop();

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;

        if (dist2[nx][ny] == -1 && grid[nx][ny] != '#') {
          dist2[nx][ny] = dist2[x][y] + 1;
          q1.push({nx, ny});
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {

        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {

          if (dist1[i][j] != -1) {

            if (dist2[i][j] == -1 || dist1[i][j] < dist2[i][j])
              return true;
          }
        }
      }
    }

    return false;
  }
};