#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarrayWithAtMostKZeros(vector<int> &nums, int k) {
    int left = 0, n = nums.size();
    int zeroCount = 0, mx = 0;
    for (int right = 0; right < n; right++) {
      zeroCount += (nums[right] == 0 ? 1 : 0);
      while (zeroCount > k) {
        zeroCount -= (nums[left] == 0 ? 1 : 0);
        left++;
      }
      mx = max(mx, right - left + 1);
    }
    return mx;
  }
};
