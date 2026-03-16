#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countFrequency(vector<int> &nums, int target) {
    int n = nums.size();
    auto first = [&]() -> int {
      int ans = -1;
      int low = 0, high = n - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
          ans = mid;
          high = mid - 1;
        } else if (nums[mid] < target) {
          low = mid + 1;
        } else
          high = mid - 1;
      }
      return ans;
    };

    auto last = [&]() -> int {
      int ans = -1;
      int low = 0, high = n - 1;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
          ans = mid;
          low = mid + 1;
        } else if (nums[mid] < target) {
          low = mid + 1;
        } else
          high = mid - 1;
      }
      return ans;
    };

    int firstOcc = first();
    int lastOcc = last();
    if(firstOcc != -1 and lastOcc != -1) {
        return (lastOcc - firstOcc) + 1;
    }

    return 0;
  }
};
