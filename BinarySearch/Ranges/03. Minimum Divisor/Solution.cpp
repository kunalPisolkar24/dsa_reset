#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int smallestDivisor(vector<int> &nums, int limit) {
    int n = nums.size();

    auto sol = [&](int d) -> int {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += (nums[i] + d - 1) / d;
      }
      return sum;
    };

    int low = 1, high = *max_element(nums.begin(), nums.end()), ans = 0;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (sol(mid) <= limit) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return ans;
  }
};
