#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isAnyWindowIncreasing(vector<int> &nums, int k) {
    int valid = 0, n = nums.size();
    for (int i = 0; i < k - 1; i++) {
      if (nums[i] < nums[i + 1])
        valid++;
    }
    if (valid == k - 1)
      return true;
    for (int right = k - 1; right < n - 1; right++) {
      int left = right - k + 1;
      if (nums[right] < nums[right + 1])
        valid++;
      if (nums[left] < nums[left + 1])
        valid--;

      if (valid == k - 1)
        return true;
    }
    return false;
  }
};
