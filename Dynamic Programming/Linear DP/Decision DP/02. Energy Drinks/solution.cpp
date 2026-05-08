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
    if (n == 1)
      return energy[0];
    ll p0 = energy[0];
    ll p1 = max(energy[0], energy[1]);
    for (int i = 2; i < n; i++) {
      long long curr = max(p1, p0 + energy[i]);
      p0 = p1;
      p1 = curr;
    }
    return p1;
  }
};
