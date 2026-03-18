#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long firstFailingPoint(long long low, long long high,
                              vector<int> &thresholds, long long limit) {
    int n = thresholds.size();

    auto f = [&](long long x) -> bool {
      long long sum = 0;
      for (int i = 0; i < n; i++) {
        sum += (long long)(thresholds[i] + x - 1) / x;
      }
      return sum <= limit;
    };

    long long ans = -1;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      if (f(mid)) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return ans;
  }
};
