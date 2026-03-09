#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> distanceFromSource(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    vector<int> dist(n, -1);
    auto bfs = [&](int src) -> void {
      queue<int> q;
      q.push(src);
      dist[src] = 0;

      while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
          int u = q.front();
          q.pop();

          for (auto v : graph[u]) {
            if (dist[v] == -1) {
              dist[v] = dist[u] + 1;
              q.push(v);
            }
          }
        }
      }
    };

    bfs(0);
    return dist;
  }
};
