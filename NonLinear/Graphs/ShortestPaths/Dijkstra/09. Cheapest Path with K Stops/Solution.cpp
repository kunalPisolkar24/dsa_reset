#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
class Solution {
public:
  /**
   * @brief Find the cheapest price from node `0` to node `n-1` with at most `k`
   * intermediate stops (at most `k+1` edges).
   *
   * @return int
   */
  int findCheapestPrice(int n, const vector<vector<int>> &edges, int k) {
    vector<vector<pii>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back({e[1], e[2]});
    }

    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
    // {weight, node , stops}
    pq.push({0, 0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
      auto [uw, u, stops] = pq.top();
      pq.pop();

      if (stops > k)
        continue;
    
      if (u == n - 1)
        return uw;

      for (auto [v, vw] : graph[u]) {
        if (uw + vw < dist[v][stops + 1]) {
          dist[v][stops + 1] = uw + vw;
          pq.push({dist[v][stops + 1], v, stops + 1});
        }
      }
    }
    return -1;
  }
};
