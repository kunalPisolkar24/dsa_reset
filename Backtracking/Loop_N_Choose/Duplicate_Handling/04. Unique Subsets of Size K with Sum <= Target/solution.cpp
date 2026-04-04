#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> uniqueSubsetsOfSizeKWithSumLimit(vector<int> &nums, int k,
                                                       int target) {
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    function<void(vector<int> &, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {
      if (sum > target or temp.size() > k)
        return;
    
      if (temp.size() == k) {
        res.push_back(temp);
        return;
      }

      for (int i = idx; i < n; i++) {
        if (i > idx and nums[i] == nums[i - 1])
          continue;
        temp.push_back(nums[i]);
        sol(temp, i + 1, sum + nums[i]);
        temp.pop_back();
      }
    };

    sol(temp, 0, 0);
    return res;
  }
};
