#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n, int k) {
    int MOD = 1e9 + 7;

    if (n == 0 or n == 1)
      return 1;

    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
        if (i - j >= 0)
          dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }

    return dp[n];
  }
};
