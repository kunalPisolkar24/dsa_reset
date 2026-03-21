#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  void reverseArray(vector<int> &arr) {
    function<void(int, int)> sol = [&](int low, int high) -> void {
      if (low <= high) {
        swap(arr[low], arr[high]);
        sol(low + 1, high - 1);
      }
      return;
    };
    int n = arr.size();
    sol(0, n - 1);
  }
};
