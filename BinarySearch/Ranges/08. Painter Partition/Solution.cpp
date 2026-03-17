#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Solution {
public:
  int minTime(vector<int> &boards, int k) {
    int n = boards.size();

    auto check = [&](int cap) -> bool {
      int count = 1;
      long long sum = 0;
      for (int i = 0; i < n; i++) {
        if (sum + boards[i] > cap) {
          count++;
          sum = 0;
        }
        sum += boards[i];
      }
      cout << count << "---" << cap << endl;
      return count <= k;
    };

    int low = *max_element(boards.begin(), boards.end()),
        high = accumulate(boards.begin(), boards.end(), 0);
    int ans = 0;

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
