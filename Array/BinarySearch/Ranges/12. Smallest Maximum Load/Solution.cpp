#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
public:
  long long minMaximumLoad(vector<int> &tasks, int k) {
    int n = tasks.size();

    auto check = [&](int cap) -> bool {
      int worker = 1;
      long long sum = 0;
      for (int i = 0; i < n; i++) {
        if (sum + tasks[i] > cap) {
          worker++;
          sum = 0;
        }
        sum += tasks[i];
      }
      cout << worker << "---" << cap << endl;
      return worker <= k;
    };

    long long low = *max_element(tasks.begin(), tasks.end()),
              high = accumulate(tasks.begin(), tasks.end(), 0);
    long long ans = high;
    while (low <= high) {
      long long mid = low + (high - low) / 2;
      if (check(mid)) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return ans;
  }
};
