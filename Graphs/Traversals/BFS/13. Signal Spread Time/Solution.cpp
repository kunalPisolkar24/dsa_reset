#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int signalSpreadTime(int n, vector<vector<int>> &edges) {
    int lev = 0;
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n, false);

    auto bfs = [&](int src) -> void {
      queue<int> q;
      q.push(src);
      vis[src] = true;

      while (!q.empty()) {
        int len = q.size();
        lev++;
        for (int i = 0; i < len; i++) {
          int u = q.front();
          q.pop();

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
    return lev - 1;
  }
};
