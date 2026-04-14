#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  /**
   * @brief A signal starts at node `0` and travels through edges with weight
   * `w` (representing time). Return the minimum time needed for the signal to
   * reach EVERY node in the graph. If some nodes are unreachable, return -1.
   *
   * @return int
   */
  int signalTime(int n, const vector<vector<int>> &edges) {
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

    int mx = INT_MIN;
    for (int i : dist) {
      if (i != INT_MAX) {
        mx = max(mx, i);
      } else
        return -1;
    }
    return mx;
  }
};
