#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> getComponentSizes(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n + 1);
    vector<bool> vis(n, false);

    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    vector<int> res;
    function<int(int)> dfs = [&](int src) -> int {
    int count = 1;
      vis[src] = true;
      for (auto v : graph[src]) {
        if (!vis[v]) {
            count += dfs(v);
        }
      }
      return count;
    };

    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        res.push_back(dfs(i));
      }
    }

    sort(res.begin(), res.end());

    return res;
  }
};
