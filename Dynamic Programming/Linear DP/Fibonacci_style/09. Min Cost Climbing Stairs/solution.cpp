#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    int p1 = 0, p2 = 0;
    for (int i = 2; i <= n; i++) {
      int jump1 = p2 + cost[i - 1];
      int jump2 = p1 + cost[i - 2];
      int curr = min(jump1, jump2);
      p1 = p2;
      p2 = curr;
    }
    return p2;
  }
};
