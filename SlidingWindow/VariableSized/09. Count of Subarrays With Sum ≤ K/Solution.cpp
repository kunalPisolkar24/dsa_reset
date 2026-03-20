#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    if (k == 0)
      return 0;

    long long count = 0, sum = 0;
    int left = 0;
    for (int right = 0; right < n; right++) {
      sum += nums[right];
      while (sum > k) {
        sum -= nums[left];
        left++;
      }
      count += (right - left + 1);
    }
    return count;
  }
};
