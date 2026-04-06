#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int n = piles.size();
    auto check = [&](int k) -> bool {
      long long count = 0;
      for (int i = 0; i < n; i++) {
        count += (piles[i] + k - 1) / k;
      }
      return count <= h;
    };

    int low = 1, high = *max_element(piles.begin(), piles.end()), ans = 0;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }

    return ans;
  }
};
