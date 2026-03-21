#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> printArray(vector<int> &arr) {
    vector<int> res;
    int n = arr.size();
    function<void(int)> sol = [&](int idx) -> void {
      if (idx == n)
        return;
      res.push_back(arr[idx]);
      sol(idx + 1);
    };
    sol(0);
    return res;
  }
};
