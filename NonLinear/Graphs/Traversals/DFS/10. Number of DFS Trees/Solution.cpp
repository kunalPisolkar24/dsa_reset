#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countDFSTrees(int n, vector<vector<int>> &edges) {
    int count = 0;
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int src) -> void {
      vis[src] = true;
      for (auto v : graph[src]) {
        if (!vis[v]) {
          dfs(v);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        count++;
        dfs(i);
      }
    }
    return count;
  }
};
