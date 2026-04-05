#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combineWithRepetition(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> res;

    function<void(vector<int> &, int)> sol = [&](vector<int> &temp, int idx) -> void {
      if(temp.size() > k) return;
      
      if (temp.size() == k) {
        res.push_back(temp);
        return;
      }

      for (int i = idx; i < n; i++) {
        temp.push_back(nums[i]);
        sol(temp, i);
        temp.pop_back();
      }
    };

    sol(temp, 0);
    return res;
  }
};
