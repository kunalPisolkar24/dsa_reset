#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * @brief From node `0`, identify the node that has the maximum shortest-path
   * distance. If multiple nodes share the same maximum distance, return the one
   * with the smallest index.
   *
   * @return int
   */
  int farthestNode(int n, const vector<vector<int>> &edges) {
    vector<int> dist(n, INT_MAX);
    vector<vector<pair<int, int>>> graph(n);
    for (auto i : edges) {
      graph[i[0]].push_back({i[1], i[2]});
      graph[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
      auto [uw, u] = pq.top();
      pq.pop();

      if (uw > dist[u])
        continue;
      for (auto [v, vw] : graph[u]) {
        if (dist[u] + vw < dist[v]) {
          dist[v] = dist[u] + vw;
          pq.push({dist[v], v});
        }
      }
    }
    int mx = INT_MIN, node = 0;
    for (int i = 0; i < dist.size(); i++) {
      if (dist[i] != INT_MAX and dist[i] > dist[node]) {
        mx = max(mx, dist[i]);
        node = i;
      }
    }
    return node;
  }
};
