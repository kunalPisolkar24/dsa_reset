#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countTreeEdges(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for (auto e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }
    for (int i = 0; i < n; i++) {
      sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> vis(n, false);
    int count = 0;
    function<void(int)> dfs = [&](int src) -> void {
        vis[src] = true;
        for(auto v: graph[src]) {
            if(!vis[v]) {
                count++;
                dfs(v);
            }
        }
    };

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }

    return count;
  }
};
