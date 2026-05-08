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
    long long p0 = coins[0];
    long long p1 = max(coins[0], coins[1]);
    for (int i = 2; i < n; i++) {
      long long curr = max(p1, p0 + coins[i]);
      p0 = p1;
      p1 = curr;
    }
    return p1;
  }
};
