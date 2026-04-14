#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * @brief You are given a weighted graph. Determine if there exists a path
   * from node `0` to node `n-1` such that the total sum of edge weights on the
   * path is less than or equal to `k`.
   *
   * @return bool
   */
  bool canReach(int n, const vector<vector<int>> &edges, int k) {
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
    if (dist[n - 1] == INT_MAX)
      return false;
    return dist[n - 1] <= k;
  }
};
