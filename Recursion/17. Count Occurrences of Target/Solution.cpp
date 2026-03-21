#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countOccurrences(vector<int> &arr, int target) {
    int n = arr.size();
    int ans = 0;
    function<void(int)> sol = [&](int idx) -> void {
      if (idx >= n)
        return;
    
      if (arr[idx] == target) {
        ans++;
      }

      sol(idx + 1);
    };
    sol(0);
    return ans;
  }
};
