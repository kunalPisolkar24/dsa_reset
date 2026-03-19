#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int k) {
    int left = 0, n = nums.size();
    int sum = 0, mx = 0;
    for (int right = 0; right < n; right++) {
      sum += nums[right];
      while (sum > k) {
        sum -= nums[left];
        left++;
      }
      mx = max(mx, right - left + 1);
    }
    return mx;
  }
};
