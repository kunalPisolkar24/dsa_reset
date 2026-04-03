#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &arr, int target) {
    int n = arr.size();
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
        if(i > idx and arr[i] == arr[i - 1]) continue;
        temp.push_back(arr[i]);
        sol(temp, i + 1, sum + arr[i]);
        temp.pop_back();
      }
    };
    sort(arr.begin(), arr.end());
    sol(temp, 0, 0);
    return res;
  }
};
