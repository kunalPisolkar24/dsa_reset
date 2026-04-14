#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
public:
  /**
   * @brief Instead of just the distance, return the actual sequence of nodes
   * (the path) that constitutes the shortest path from node `0` to node `n-1`.
   *
   * @return vector<int>
   */
  vector<int> shortestPath(int n, const vector<vector<int>> &edges) {
    vector<int> dist(n, INT_MAX), parent(n, -1);
    vector<vector<pair<int, int>>> graph(n);
    for (auto i : edges) {
      graph[i[0]].push_back({i[1], i[2]});
      graph[i[1]].push_back({i[0], i[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> res;
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
          parent[v] = u;
          pq.push({dist[v], v});
        }
      }
    }
    int node = n - 1;
    while (node != -1) {
      res.push_back(node);
      node = parent[node];
    }
    reverse(res.begin(), res.end());

    if(dist[n - 1] == INT_MAX) return {};
    return res;
  }
};
