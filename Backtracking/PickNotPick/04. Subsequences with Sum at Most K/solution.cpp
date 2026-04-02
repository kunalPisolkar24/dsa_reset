#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsequencesWithSumAtMostK(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> res;

    function<void(vector<int> &, int, int)> sol =
        [&](vector<int> &temp, int idx, int sum) -> void {
            
      if (sum > target)
        return;

      if (idx >= n) {
        if (sum <= target and !temp.empty()) {
          res.push_back(temp);
        }
        return;
      }

      sol(temp, idx + 1, sum);

      temp.push_back(arr[idx]);
      sol(temp, idx + 1, sum + arr[idx]);
      temp.pop_back();
    };

    vector<int> temp;
    sol(temp, 0, 0);
    return res;
  }
};
