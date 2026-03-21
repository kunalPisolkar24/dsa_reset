#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &arr) {
    int mn = numeric_limits<int>::max();

    int n = arr.size();
    function<void(int)> sol = [&](int idx) -> void {
      if (idx < 0)
        return;
      mn = min(mn, arr[idx]);
      sol(idx - 1);
    };

    sol(n - 1);
    return mn;
  }
};
