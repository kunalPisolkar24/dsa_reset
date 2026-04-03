#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> combine(vector<int> &arr, int k) {
    vector<int> temp;
    int n = arr.size();
    vector<vector<int>> res;
    function<void(vector<int> &, int)> sol = [&](vector<int> &temp,
                                                 int idx) -> void {
      if (temp.size() == k) {
        res.push_back(temp);
        return;
      }

      for (int i = idx; i < n; i++) {
        temp.push_back(arr[i]);
        sol(temp, i + 1);
        temp.pop_back();
      }
    };
    sol(temp, 0);
    return res;
  }
};
