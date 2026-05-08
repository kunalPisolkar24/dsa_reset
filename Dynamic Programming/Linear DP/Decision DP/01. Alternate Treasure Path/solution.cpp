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
    if (n == 1)
      return coins[0];
    vector<long long> dp(n + 1, 0);
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);
    for (int i = 2; i < n; i++) {
      long long skip = dp[i - 1];
      long long choose = INT_MIN;
      if (i - 2 >= 0) {
        choose = dp[i - 2] + coins[i];
      }
      dp[i] = max(skip, choose);
    }
    return dp[n - 1];
  }
};
