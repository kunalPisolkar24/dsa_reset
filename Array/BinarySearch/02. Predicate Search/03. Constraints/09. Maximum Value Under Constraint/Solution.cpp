#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long maxValueUnderConstraint(vector<int> &nums, long long budget) {
    int n = nums.size();
    auto check = [&](long long mn) -> bool {
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        long long add = min((long long)nums[i], mn);
        if (sum + add > budget)
          return false;
        sum += add;
      }
      return true;
    };

    long long low = 1, high = 1e14;
    long long ans = 0;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return ans;
  }
};
