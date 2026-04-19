#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
class Solution {
public:
  /**
   * @brief In a graph where all edges have weight either 0 or 1, find the
   * shortest distance from node `0` to all other nodes. This can be solved more
   * efficiently than standard Dijkstra.
   *
   * @return vector<int>
   */
  vector<int> binaryShortestPath(int n, const vector<vector<int>> &edges) {
    vector<vector<pii>> graph(n);
    for (auto i : edges) {
      graph[i[0]].push_back({i[1], i[2]});
      graph[i[1]].push_back({i[0], i[2]});
    }

    vector<int> dist(n, INT_MAX);
    deque<int> dq;
    dq.push_front(0);
    dist[0] = 0;

    while (!dq.empty()) {
      auto u = dq.front();
      dq.pop_front();

      for (auto [v, vw] : graph[u]) {
        if (dist[u] + vw < dist[v]) {
          dist[v] = dist[u] + vw;
          if (vw == 0)
            dq.push_front(v);
          else
            dq.push_back(v);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (dist[i] == INT_MAX)
        dist[i] = -1;
    }
    return dist;
  }
};
