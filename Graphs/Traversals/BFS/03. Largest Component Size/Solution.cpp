#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int largestComponentSize(int n, vector<vector<int>> &edges) {
    int mx = 0;
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<bool> vis(n, false);

    auto bfs = [&](int src) -> int {
      int count = 0;
      queue<int> q;
      q.push(src);
      vis[src] = true;

      while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        for (auto v : graph[u]) {
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
        }
      }
      return count;
    };

    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        mx = max(mx, bfs(i));
      }
    }

    return mx;
  }
};
