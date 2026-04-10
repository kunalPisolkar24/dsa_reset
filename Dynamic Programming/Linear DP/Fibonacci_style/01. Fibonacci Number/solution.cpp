#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int fib(int N) {
    vector<int> dp(N + 1, -1);
    function<int(int)> sol = [&](int n) -> int {
      if (n <= 1)
        return n;
      if (dp[n] != -1)
        return dp[n];
      return dp[n] = sol(n - 1) + sol(n - 2);
    };
    return sol(N);
  }
};
