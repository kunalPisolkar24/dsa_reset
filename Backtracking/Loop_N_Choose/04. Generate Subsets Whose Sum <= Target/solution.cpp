#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithSumLimit(vector<int> &arr, int target) {
    int n = arr.size();
    vector<int> temp;
    vector<vector<int>> res;
    function<void(vector<int> &, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {
      if (sum > target) {
        return;
      }
      res.push_back(temp);
      for (int i = idx; i < n; i++) {
        temp.push_back(arr[i]);
        sol(temp, i + 1, sum + arr[i]);
        temp.pop_back();
      }
    };
    sol(temp, 0, 0);
    return res;
  }
};
