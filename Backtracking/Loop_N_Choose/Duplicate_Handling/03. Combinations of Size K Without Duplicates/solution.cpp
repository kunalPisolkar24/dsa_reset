#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combineUnique(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    function<void(vector<int> &, int)> sol = [&](vector<int> &temp,
                                                 int idx) -> void {
      if (temp.size() > k)
        return;

      if (temp.size() == k) {
        res.push_back(temp);
        return;
      }

      for (int i = idx; i < n; i++) {
        if (i > idx and nums[i] == nums[i - 1])
          continue;
        temp.push_back(nums[i]);
        sol(temp, i + 1);
        temp.pop_back();
      }
    };
    sol(temp, 0);
    return res;
  }
};
