#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMax(vector<int> &arr) {
    int mx = numeric_limits<int>::min();
    int n = arr.size();
    function<void(int)> sol = [&](int idx) -> void {
      if (idx < 0)
        return;
      mx = max(mx, arr[idx]);
      sol(idx - 1);
    };
    sol(n - 1);
    return mx;
  }
};
