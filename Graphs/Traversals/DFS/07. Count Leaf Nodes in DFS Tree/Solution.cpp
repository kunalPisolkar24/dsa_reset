#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countLeafNodes(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n, false);

    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    for (int i = 0; i < n; i++)
      sort(graph[i].begin(), graph[i].end());

    int count = 0;
    function<void(int)> dfs = [&](int src) -> void {
      vis[src] = true;
      bool f = false;
      for (auto v : graph[src]) {
        if (!vis[v]) {
          f = true;
          dfs(v);
        }
      }
      if (f == false)
        count++;
    };

    dfs(0);

    return count;
  }
};
