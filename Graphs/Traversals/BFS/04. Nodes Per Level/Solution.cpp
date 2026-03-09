#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> nodesPerLevel(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    vector<int> res;
    vector<bool> vis(n, false);
    auto bfs = [&](int src) -> void {
      queue<int> q;
      q.push(src);
      vis[src] = 1;
      while (!q.empty()) {
        int len = q.size();
        for (int lev = 0; lev < len; lev++) {
          int u = q.front();
          q.pop();

          for (auto v : graph[u]) {
            if (!vis[v]) {
              vis[v] = true;
              q.push(v);
            }
          }
        }
        res.push_back(len);
      }
    };
    bfs(0);
    return res;
  }
};
