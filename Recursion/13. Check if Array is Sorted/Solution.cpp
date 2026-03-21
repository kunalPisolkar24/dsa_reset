#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isSorted(vector<int> &arr) {
    int n = arr.size();
    if (n == 1)
      return true;
    bool res = true;
    function<void(int)> sol = [&](int idx) -> void {
      if (!res or idx >= n)
        return;
      if (arr[idx - 1] > arr[idx]) {
        res = false;
      }
      sol(idx + 1);
    };
    sol(1);
    return res;
  }
};
