#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(vector<int> &arr) {
    bool res = true;
    function<void(int, int)> sol = [&](int low, int high) -> void {
      if(!res) return;
      if (low <= high) {
        if (arr[low] != arr[high]) {
          res = false;
          return;
        }
        sol(low + 1, high - 1);
      }
      return;
    };
    int n = arr.size();
    sol(0, n - 1);
    return res;
  }
};