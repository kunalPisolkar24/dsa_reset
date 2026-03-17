#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int allocateBooks(vector<int> &pages, int m) {
    int n = pages.size();
    if(m > n) return -1;
    
    auto check = [&](int cap) -> bool {
      int count = 1;
      long long sum = 0;
      for (int i = 0; i < n; i++) {
        if (sum + pages[i] > cap) {
          count++;
          sum = 0;
        }
        sum += pages[i];
      }
      return count <= m;
    };

    int low = *max_element(pages.begin(), pages.end()), high = accumulate(pages.begin(), pages.end(), 0);
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