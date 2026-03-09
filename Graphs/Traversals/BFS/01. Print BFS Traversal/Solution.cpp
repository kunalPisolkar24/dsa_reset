#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> bfsTraversal(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < n; i++) {
            sort(graph[i].begin(), graph[i].end());
        }

        vector<int> res; 

        vector<bool> vis(n, false);
        auto bfs = [&](int src) -> void {
            queue<int> q;
            q.push(src);
            vis[src] = true;

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                res.push_back(u);

                for(auto v: graph[u]) {
                    if(!vis[v]) {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        };

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                bfs(i);
            }
        }
        return res;
    }
};
