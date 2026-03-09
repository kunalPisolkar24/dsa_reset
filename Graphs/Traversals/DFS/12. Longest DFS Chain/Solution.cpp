#include "bits/stdc++.h"
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
  int longestDFSChain(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n + 1);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < n; i++)
      sort(graph[i].begin(), graph[i].end());

    vector<int> dist(n, -1);

    function<void(int)> dfs = [&](int src) -> void {
      for (auto v : graph[src]) {
        if (dist[v] == -1) {
          dist[v] = dist[src] + 1;
          dfs(v);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      if (dist[i] == -1) {
        dist[i] = 0;
        dfs(i);
      }
    }

    return *max_element(dist.begin(), dist.end());
  }
};
