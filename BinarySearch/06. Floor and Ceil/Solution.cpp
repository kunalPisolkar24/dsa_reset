#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  pair<int, int> findFloorCeil(vector<int> &nums, int target) {
    int n = nums.size();

    auto getCeil = [&]() -> int {
      int low = 0, high = n - 1, ans = n;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) {
          ans = mid;
          high = mid - 1;
        } else if (nums[mid] < target)
          low = mid + 1;
      }
      return (ans == n ? -1 : ans);
    };

    auto getFloor = [&]() -> int {
      int low = 0, high = n - 1, ans = n;
      while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) {
          ans = mid;
          low = mid + 1;
        } else
          high = mid - 1;
      }
      return (ans == n ? -1 : ans);
    };

    int floorEl = getFloor(), ceilEl = getCeil();
    if (floorEl != -1 and ceilEl != -1) {
      return {nums[floorEl], nums[ceilEl]};
    } else if (floorEl == -1 and ceilEl != -1) {
      return {-1, nums[ceilEl]};
    } else if (floorEl != -1 and ceilEl == -1) {
      return {nums[floorEl], -1};
    }

    return {-1, -1};
  }
};
