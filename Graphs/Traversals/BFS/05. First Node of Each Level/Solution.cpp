#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> firstNodePerLevel(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    for (int i = 0; i < n; i++) {
      sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> vis(n, false);
    vector<int> res;
    auto bfs = [&](int src) -> void {
      queue<int> q;
      q.push(src);
      vis[src] = true;

      while (!q.empty()) {
        int len = q.size(), f = 0;
        for (int lev = 0; lev < len; lev++) {
          int u = q.front();
          q.pop();
          if (!f) {
            res.push_back(u);
            f = true;
          }
          for (auto v : graph[u]) {
            if (!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
          }
        }
      }
    };

    bfs(0);
    return res;
  }
};
