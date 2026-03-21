#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> printReverse(vector<int> &arr) {
    vector<int> res;
    int n = arr.size();
    function<void(int)> sol = [&](int idx) -> void {
      if (idx < 0)
        return;
      res.push_back(arr[idx]);
      sol(idx - 1);
    };
    sol(n - 1);
    return res;
  }
};
