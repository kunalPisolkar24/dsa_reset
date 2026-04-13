#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
      int jump1 = dp[i - 1] + cost[i - 1];
      int jump2 = dp[i - 2] + cost[i - 2];
      dp[i] = min(jump1, jump2);
    }
    return dp[n];
  }
};
