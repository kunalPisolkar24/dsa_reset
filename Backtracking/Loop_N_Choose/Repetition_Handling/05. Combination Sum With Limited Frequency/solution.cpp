#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSumFreq(vector<int> &nums, vector<int> &freq,
                                         int target) {
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> res;

    function<void(vector<int> &, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {

      if (sum == target) {
        res.push_back(temp);
        return;
      }

      if (idx == n or sum > target)
        return;

      for (int i = 0; i <= freq[idx]; i++) {
        int newTotal = i * nums[idx];
        int newSum = sum + newTotal;

        if (newSum > target)
          break;

        for (int j = 0; j < i; j++) {
          temp.push_back(nums[idx]);
        }

        sol(temp, idx + 1, newSum);

        for (int j = 0; j < i; j++) {
          temp.pop_back();
        }
      }
    };

    sol(temp, 0, 0);
    return res;
  }
};
