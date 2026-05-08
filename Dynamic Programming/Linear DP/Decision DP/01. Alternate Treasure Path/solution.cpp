#include <bits/stdc++.h>

using namespace std;

/**
 * Problem 1: Alternate Treasure Path
 *
 * From index i:
 * 1. Take coins[i] and move to i + 2
 * 2. Skip coins[i] and move to i + 1
 *
 * Return max coins starting from index 0.
 */
class Solution {
public:
  long long maxCoins(vector<int> &coins) {
    int n = coins.size();
    vector<long long> dp(n, -1);
    function<long long(int)> sol = [&](int i) -> long long {
      if (i >= n)
        return 0;

      if (dp[i] != -1)
        return dp[i];

      long long skip = sol(i + 1);

      long long choose = coins[i] + sol(i + 2);

      return dp[i] = max(skip, choose);
    };

    return sol(0);
  }
};
