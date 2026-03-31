#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> replaceWithSum(vector<int> &arr) {
    function<int(int)> getSum = [&](int idx) -> int {
      if (idx >= arr.size())
        return 0;
      return getSum(idx + 1) + arr[idx];
    };

    int sum = getSum(0);
    vector<int> res;
    function<void(int)> sol = [&](int idx) -> void {
      if (idx >= arr.size())
        return;
      res.push_back(sum - arr[idx]);
      sol(idx + 1);
    };

    sol(0);
    return res;
  }
};
