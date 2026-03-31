#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> moveZeros(vector<int> &arr) {
    int pos = 0;
    function<void(int)> sol = [&](int idx) -> void {
      if (idx >= arr.size())
        return;
      if (arr[idx] != 0) {
        swap(arr[idx], arr[pos]);
        pos++;
      }
      sol(idx + 1);
    };
    sol(0);
    return arr;
  }
};
