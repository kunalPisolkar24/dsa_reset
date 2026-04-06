#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long minTimeToCompleteTasks(vector<int> &times, int k) {
    int n = times.size();

    auto check = [&](long long time) -> bool {
      long long total = 0;
      for (int i = 0; i < n; i++) {
        total += (time / times[i]);
      }
      return total >= k;
    };

    long long low = 1, high = *max_element(times.begin(), times.end()) * k;
    long long ans = 0;
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
