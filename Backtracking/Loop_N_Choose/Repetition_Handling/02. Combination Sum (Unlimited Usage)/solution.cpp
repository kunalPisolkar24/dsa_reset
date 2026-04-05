#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    int n = candidates.size();
    vector<int> temp;
    vector<vector<int>> res;

    function<void(vector<int> &, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {
      if (sum > target)
        return;

      if (sum == target) {
        res.push_back(temp);
        return;
      }

      for (int i = idx; i < n; i++) {
        temp.push_back(candidates[i]);
        sol(temp, i, sum + candidates[i]);
        temp.pop_back();
      }
    };

    sol(temp, 0, 0);

    return res;
  }
};
