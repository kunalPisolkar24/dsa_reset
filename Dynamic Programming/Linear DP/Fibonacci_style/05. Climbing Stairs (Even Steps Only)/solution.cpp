#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n & 1)
      return 0;

    int MOD = 1e9 + 7;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    if (n >= 2)
      dp[2] = 1;
    if (n >= 4)
      dp[4] = 2;

    for (int i = 6; i <= n; i += 2) {
      dp[i] = (dp[i - 2] + dp[i - 4]) % MOD;
    }
    return dp[n];
  }
};
