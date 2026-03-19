#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxEvenNumbers(vector<int> &nums, int k) {
    int evenCount = 0;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      if (nums[i] % 2 == 0)
        evenCount++;
    }
    
    int mx = evenCount;
    for (int right = k; right < n; right++) {
      evenCount -= (nums[right - k] % 2 == 0 ? 1 : 0);
      evenCount += (nums[right] % 2 == 0 ? 1 : 0);
      mx = max(evenCount, mx);
    }

    return mx;
  }
};
