#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    long long sum = 0;
    int n = nums.size();
    for (int i = 0; i < k; i++) {
      sum += nums[i];
    }
    double mx = sum;

    for (int right = k; right < n; right++) {
      sum -= nums[right - k];
      sum += nums[right];
      mx = max((double) sum, mx);
    }
    return mx / k;
  }
};
