#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubarraysWithKZeros(vector<int> &nums, int k) {
    int n = nums.size();

    auto sol = [&](int k) -> int {
      int left = 0, count = 0, zeroCount = 0;
      if (k < 0)
        return 0;
      for (int right = 0; right < n; right++) {
        zeroCount += (nums[right] == 0);
        while (zeroCount > k) {
          zeroCount -= (nums[left] == 0);
          left++;
        }
        count += (right - left + 1);
      }
      return count;
    };

    return sol(k) - sol(k - 1);
  }
};
