#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp;
    vector<vector<int>> res;

    function<void(vector<int> &, int)> sol = [&](vector<int> &temp,
                                                 int idx) -> void {
      res.push_back(temp);
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
