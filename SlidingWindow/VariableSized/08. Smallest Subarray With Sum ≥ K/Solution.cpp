#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int smallestSubarray(vector<int> &nums, int k) {
    int left = 0, n = nums.size(), mn = numeric_limits<int>::max();
    int sum = 0;
    for (int right = 0; right < n; right++) {
      sum += nums[right];
      while (sum >= k) {
        mn = min(mn, right - left + 1);
        sum -= nums[left];
        left++;
      }
    }
    return (mn == numeric_limits<int>::max() ? -1 : mn);
  }
};
