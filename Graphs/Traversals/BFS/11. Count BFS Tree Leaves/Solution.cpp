#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countBFSTreeLeaves(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    
    for(int i = 0; i < n; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    vector<int> vis(n, false);

    int count = 0;
    auto bfs = [&](int src) -> void {
      queue<int> q;
      q.push(src);
      vis[src] = true;

      while (!q.empty()) {
        int u = q.front();
        q.pop();
        bool flag = true;
        for (auto v : graph[u]) {
          if (!vis[v]) {
            flag = false;
            vis[v] = true;
            q.push(v);
          }
        }

        count += flag;
      }
    };
    bfs(0);
    return count;
  }
};
