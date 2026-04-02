#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsequencesOfLengthK(vector<int> &arr, int k) {
    int n = arr.size();
    vector<vector<int>> res;
    function<void(vector<int> &, int)> sol = [&](vector<int> &temp,
                                                 int idx) -> void {
      if (temp.size() > k)
        return;

      if (idx >= n) {
        if (temp.size() == k) {
          res.push_back(temp);
        }
        return;
      }

      sol(temp, idx + 1);

      temp.push_back(arr[idx]);
      sol(temp, idx + 1);
      temp.pop_back();
    };
    vector<int> temp;
    sol(temp, 0);
    return res;
  }
};
