#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n, vector<int> &steps) {
    if(n == 0 or n == 1) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    int MOD = 1e9 + 7;

    for (int i = 1; i <= n; i++) {
      for (auto j : steps) {
        if (i - j >= 0)
          dp[i] = (dp[i] + dp[i - j]) % MOD;
      }
    }
    return dp[n];
  }
};
