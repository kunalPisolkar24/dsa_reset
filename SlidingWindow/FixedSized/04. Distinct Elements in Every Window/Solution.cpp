#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> countDistinct(vector<int> &nums, int k) {
    unordered_map<int, int> ump;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      ump[nums[i]]++;
    }
    res.push_back(ump.size());
    for (int right = k; right < n; right++) {
      ump[nums[right - k]]--;
      if (ump[nums[right - k]] == 0) {
        ump.erase(nums[right - k]);
      }
      ump[nums[right]]++;
      res.push_back(ump.size());
    }
    return res;
  }
};
