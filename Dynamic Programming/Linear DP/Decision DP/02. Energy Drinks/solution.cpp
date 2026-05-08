#include <bits/stdc++.h>

using namespace std;

/**
 * Problem 2: Energy Drinks
 *
 * If you drink at checkpoint i, you cannot drink at checkpoint i + 1.
 * Find max energy.
 */
typedef long long ll;
class Solution {
public:
  long long maxEnergy(vector<int> &energy) {
    int n = energy.size();
    vector<ll> dp(n + 1, -1);
    function<ll(int)> sol = [&](int idx) -> ll {
      if (idx >= n)
        return 0;
      if (dp[idx] != -1)
        return dp[idx];
      long long skip = sol(idx + 1);
      long long choose = energy[idx] + sol(idx + 2);
      return dp[idx] = max(choose, skip);
    };
    return sol(0);
  }
};
