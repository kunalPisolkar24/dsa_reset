#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> closestSpecialNode(int n, vector<vector<int>> &edges,
                                 vector<int> &specialNodes) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<int> dist(n, -1);

    auto bfs = [&]() -> void {
      queue<int> q;
      for (auto i : specialNodes) {
        q.push(i);
        dist[i] = 0;
      }

      while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : graph[u]) {
          if (dist[v] == -1) {
            dist[v] = 1 + dist[u];
            q.push(v);
          }
        }
      }
    };
    
    bfs();
    return dist;
  }
};
