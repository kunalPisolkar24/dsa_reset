#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int n = dist.size();
    if (hour <= n - 1) return -1;
    auto check = [&](int cap) -> bool {
      long double total = 0;
      for (int i = 0; i < n - 1; i++) {
        total += (dist[i] + cap - 1) / cap;
      }
      total += (long double)dist[n - 1] / cap;
      return total <= hour + 1e-9;
    };

    long long low = 1, high = 1e9;
    int ans = -1;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return ans;
  }
};
