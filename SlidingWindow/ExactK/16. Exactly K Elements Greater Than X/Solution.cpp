#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubarraysWithKGreater(vector<int> &nums, int k, int x) {
    int n = nums.size();

    auto sol = [&](int k) -> int {
      if (k < 0)
        return 0;
      int left = 0, count = 0, greater = 0;
      for (int right = 0; right < n; right++) {
        greater += (nums[right] > x);
        while (greater > k) {
          greater -= (nums[left] > x);
          left++;
        }
        count += (right - left + 1);
      }
      return count;
    };

    return sol(k) - sol(k - 1);
  }
};
