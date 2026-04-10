#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    function<int(int)> sol = [&](int n) -> int {
      if (n < 0)
        return 0;
      if (dp[n] != -1)
        return dp[n];
      if (n == 0 or n == 1)
        return 1;
      return dp[n] = sol(n - 1) + sol(n - 2);
    };
    return sol(n);
  }
};
