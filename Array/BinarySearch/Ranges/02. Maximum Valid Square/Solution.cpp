#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long maxValidSquare(long long x) {
    long long low = 0, high = x, ans = x;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      long long val = mid * mid;
      if (val <= x) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    return ans;
  }
};
