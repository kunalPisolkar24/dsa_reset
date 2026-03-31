#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int findLast(vector<int> &arr, int target) {
    function<int(int)> sol = [&](int idx) -> int {
      if (idx < 0)
        return -1;
      if (arr[idx] == target) {
        return idx;
      }
      return sol(idx - 1);
    };

    return sol(arr.size() - 1);
  }
};
