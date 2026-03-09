#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> buildParentTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    vector<int> parent(n, -1);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < n; i++) {
      sort(graph[i].begin(), graph[i].end());
    }

    auto bfs = [&](int src) -> void {
      queue<int> q;
      q.push(src);
      parent[src] = 0;
      while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
          int u = q.front();
          q.pop();
          for (auto v : graph[u]) {
            if (parent[v] == -1) {
              parent[v] = u;
              q.push(v);
            }
          }
        }
      }
    };
    bfs(0);
    parent[0] = -1;
    return parent;
  }
};