#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxWindowSum(vector<int> &nums, int k) {
    int sum = 0, n = nums.size(), mx = numeric_limits<int>::min();

    for (int i = 0; i < k; i++)
      sum += nums[i];

    mx = max(mx, sum);

    for (int right = k; right < n; right++) {
      sum -= nums[right - k];
      sum += nums[right];
      mx = max(mx, sum);
    }
    return mx;
  }
};
