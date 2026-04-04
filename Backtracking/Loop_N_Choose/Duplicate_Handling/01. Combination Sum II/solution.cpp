#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    int n = candidates.size();

    vector<int> temp;
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());

    function<void(vector<int> &, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {
      if (sum > target)
        return;

      if (sum == target) {
        res.push_back(temp);
        return;
      }

      for (int i = idx; i < n; i++) {
        if (i > idx and candidates[i] == candidates[i - 1])
          continue;
        temp.push_back(candidates[i]);
        sol(temp, i + 1, sum + candidates[i]);
        temp.pop_back();
      }
    };

    sol(temp, 0, 0);
    return res;
  }
};
