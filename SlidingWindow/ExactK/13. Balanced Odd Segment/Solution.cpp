#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubarraysWithKOdds(vector<int> &nums, int k) {
    int n = nums.size();

    auto sol = [&](int k) -> int {
      int oddCount = 0;
      if(k < 0) return 0;
      int left = 0, count = 0;
      for (int right = 0; right < n; right++) {
        oddCount += (nums[right] & 1);
        while (oddCount > k) {
          oddCount -= (nums[left] & 1);
          left++;
        }
        count += (right - left + 1);
      }
      return count;
    };

    return sol(k) - sol(k - 1);
  }
};
