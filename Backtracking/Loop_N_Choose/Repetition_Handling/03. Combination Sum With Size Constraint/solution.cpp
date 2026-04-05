#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSumK(vector<int> &nums, int target, int k) {
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> res;
    function<void(vector<int> & temp, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {
      if (sum > target or temp.size() > k)
        return;

      if (temp.size() == k and sum == target) {
        res.push_back(temp);
        return;
      }
      for (int i = idx; i < n; i++) {
        temp.push_back(nums[i]);
        sol(temp, i, sum + nums[i]);
        temp.pop_back();
      }
    };
    sol(temp, 0, 0);
    return res;
  }
};
