#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> dfsTraversal(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n + 1);

    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    for (int i = 0; i < n; i++)
      sort(graph[i].begin(), graph[i].end());

    vector<int> res;
    vector<bool> vis(n, false);

    function<void(int)> dfs = [&](int src) -> void {
      vis[src] = true;
      res.push_back(src);
      for (auto v : graph[src]) {
        if (!vis[v])
          dfs(v);
      }
    };

    for (int i = 0; i < vis.size(); i++) {
      if (!vis[i])
        dfs(i);
    }

    return res;
  }
};
