#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCost(vector<int> &heights) {
    int n = heights.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++) {
      dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]),
                  dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    return dp[n - 1];
  }
};
