#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    function<int(int)> sol = [&](int n) -> int {
      if (n < 0)
        return 0;
      if (n == 1 or n == 0)
        return 1;
      if (dp[n] != -1)
        return dp[n];
      return dp[n] = sol(n - 1) + sol(n - 2) + sol(n - 3);
    };
    return sol(n);
  }
};
