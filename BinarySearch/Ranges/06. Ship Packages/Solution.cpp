#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int n = weights.size();

    auto check = [&](int cap) -> bool {
      int sum = 0, count = 1;
      for (int i = 0; i < n; i++) {

        if (weights[i] > cap)
          return false;

        if (sum + weights[i] > cap) {
          count++;
          sum = 0;
        }
        sum += weights[i];
      }
      return count <= days;
    };

    int low = 1, high = accumulate(weights.begin(), weights.end(), 0),
        ans = high;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return ans;
  }
};
