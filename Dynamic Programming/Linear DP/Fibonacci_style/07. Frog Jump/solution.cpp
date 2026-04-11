#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCost(vector<int> &heights) {
    int n = heights.size();
    vector<int> dp(n + 1, -1);
    function<int(int)> sol = [&](int n) -> int {
      if (n == 0)
        return 0;
      if (dp[n] != -1)
        return dp[n];

      int jump1 = INT_MAX, jump2 = INT_MAX;

      jump1 = sol(n - 1) + abs(heights[n] - heights[n - 1]);

      if (n > 1) {
        jump2 = sol(n - 2) + abs(heights[n] - heights[n - 2]);
      }

      return dp[n] = min(jump1, jump2);
    };
    return sol(n - 1);
  }
};
