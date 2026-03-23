#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int subarraysWithKDistinct(vector<int> &nums, int k) {
    int n = nums.size();
    
    auto sol = [&](int k) -> int {
      unordered_map<int, int> ump;
      int left = 0, count = 0;
      for (int right = 0; right < n; right++) {
        ump[nums[right]]++;
        while (ump.size() > k) {
          ump[nums[left]]--;
          if (ump[nums[left]] == 0) {
            ump.erase(nums[left]);
          }
          left++;
        }
        count += (right - left + 1);
      }
      return count;
    };

    return sol(k) - sol(k - 1);
  }
};
