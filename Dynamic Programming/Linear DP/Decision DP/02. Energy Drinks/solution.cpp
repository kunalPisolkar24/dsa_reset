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
    vector<ll> dp(n + 1, 0);
    if (n == 1)
      return energy[0];
    dp[0] = energy[0];
    dp[1] = max(energy[0], energy[1]);
    for (int i = 2; i < n; i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + energy[i]);
    }
    return dp[n - 1];
  }
};
