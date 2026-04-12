#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n, int k) {
    int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    long long sum = dp[0];
    for (int right = 1; right <= n; right++) {
      dp[right] = sum % MOD;
      sum = (sum + dp[right]) % MOD;
      if (right - k >= 0) {
        sum = (sum - dp[right - k] + MOD) % MOD;
      }
    }

    return dp[n];
  }
};
