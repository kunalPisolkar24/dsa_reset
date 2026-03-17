#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long minSquareThreshold(long long x) {
    long long low = 0, high = x, ans = high;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      long long int val = mid * mid;
      if(val >= x) {
        ans = mid;
        high = mid - 1;
      } else low = mid + 1;
    }
    return ans;
  }
};
