#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minCost(vector<int> &heights) {
    int n = heights.size();
    int p1 = 0;
    int p2 = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++) {
      int curr = min(p2 + abs(heights[i] - heights[i - 1]),
                     p1 + abs(heights[i] - heights[i - 2]));
      p1 = p2;
      p2 = curr;
    }
    return p2;
  }
};
