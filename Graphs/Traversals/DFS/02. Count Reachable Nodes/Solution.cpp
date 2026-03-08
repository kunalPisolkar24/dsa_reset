#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
  int countReachable(int n, vector<vector<int>> &edges, int start) {
    int count = 0;
    vector<vector<int>> graph(n + 1);
    for(auto e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<bool> vis(n, false);

    function<void(int)> dfs = [&](int src) -> void {
        vis[src] = true;
        count++;
        for(auto v: graph[src]) {
            if(!vis[v]) 
                dfs(v);
        }
    };
    
    dfs(start);
    return count;
  }
};
