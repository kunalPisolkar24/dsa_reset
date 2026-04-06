#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxMinDistance(vector<int> &positions, int k) {
    int n = positions.size();
    sort(positions.begin(), positions.end());

    auto check = [&](int dist) -> bool {
      int placed = 1;
      int prev = positions[0];
      for (int i = 1; i < n; i++) {
        if (positions[i] - prev >= dist) {
          placed++;
          prev = positions[i];
        }
      }
      return placed >= k;
    };

    int low = 0, high = positions[n - 1] - positions[0];
    int ans = 0;

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return ans;
  }
};
