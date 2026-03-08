#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  bool hasPath(int n, vector<vector<int>> &edges, int u, int v) {
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n, false);

    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    bool f = false;
    function<void(int)> dfs = [&](int src) -> void {
      vis[src] = true;
      if (src == v)
        f = true;
      for (auto v : graph[src]) {
        if (!vis[v])
          dfs(v);
      }
    };

    dfs(u);

    return f;
  }
};
