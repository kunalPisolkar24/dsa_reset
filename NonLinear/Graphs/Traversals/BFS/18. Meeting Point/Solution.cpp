#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  vector<int> meetingPoint(int n, vector<vector<int>> &edges,
                           vector<int> &group1, vector<int> &group2) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<int> dist1(n, -1), dist2(n, -1);
    auto bfs = [&](vector<int> sources, vector<int> &dist) -> void {
      queue<int> q;
      for (auto i : sources) {
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

    bfs(group1, dist1);
    bfs(group2, dist2);

    vector<int> temp(n, -1);
    int mn = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
      if (dist1[i] == -1 or dist2[i] == -1)
        continue;
      int val = max(dist1[i], dist2[i]);
      mn = min(val, mn);
      temp[i] = val;
    }

    vector<int> res;
    for (int i = 0; i < temp.size(); i++) {
      if (temp[i] == mn) {
        res.push_back(i);
      }
    }
    return res;
  }
};
