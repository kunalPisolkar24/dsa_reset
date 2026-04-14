#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * @brief Given a weighted undirected graph with `n` nodes and `edges` where
   * each edge is `[u, v, w]`, find the shortest distance from node `0` to all
   * other nodes.
   *
   * @return vector<int>
   */
  vector<int> shortestDistance(int n, const vector<vector<int>> &edges) {
    vector<int> dist(n, numeric_limits<int>::max());
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
      auto [w, u] = pq.top();
      pq.pop();

      if(w > dist[u]) continue;
      for (auto [v, vw] : graph[u]) {
        if (dist[u] + vw < dist[v]) {
          dist[v] = dist[u] + vw;
          pq.push({dist[v], v});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist[i] == numeric_limits<int>::max()) {
        dist[i] = -1;
      }
    }
    return dist;
  }
};
