#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int n = bloomDay.size();
    if ((n / k) < m)
      return -1;

    auto check = [&](int dayCap) -> bool {
      int group = 0;
      int count = 0;
      for(int i = 0; i < n; i++){
        if(bloomDay[i] <= dayCap) {
          count++;
        }else {
          count = 0;
        }

        if(count == k){
          group++;
          count = 0;
        }
      }
      return group >= m;
    };

    auto [mn, mx] = minmax_element(bloomDay.begin(), bloomDay.end());
    int low = *mn, high = *mx;
    int ans = -1;
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
