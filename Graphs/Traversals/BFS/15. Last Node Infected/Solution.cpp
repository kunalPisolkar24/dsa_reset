#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int lastNodeInfected(int n, vector<vector<int>> &edges,
                       vector<int> &sources) {
    int mxDist = numeric_limits<int>::min(), mxEl = -1;
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    vector<int> dist(n, -1);
    auto bfs = [&]() {
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
            dist[v] = dist[u] + 1;
            q.push(v);
          }
        }
      }
    };

    bfs();
    for (int i = 0; i < n; i++) {
      if (mxDist < dist[i]) {
        mxDist = dist[i];
        mxEl = i;
      }
    }
    return mxEl;
  }
};
