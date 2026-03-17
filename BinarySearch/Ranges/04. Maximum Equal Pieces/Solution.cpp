#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxPieceLength(vector<int> &nums, int k) {
    int n = nums.size();

    auto check = [&](int length) -> bool {
      long long count = 0;
      for (int i = 0; i < nums.size(); i++) {
        count += nums[i] / length;
        if(count >= k) return true;
      }
      return false;
    };

    int low = 1, high = *max_element(nums.begin(), nums.end()), ans = 0;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return ans;
  }
};
