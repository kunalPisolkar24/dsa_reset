#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size(), ans = -1;
    int low = 0, high = n - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        ans = mid;
        low = mid + 1;
      } else if (nums[mid] < target)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return ans;
  }
};
