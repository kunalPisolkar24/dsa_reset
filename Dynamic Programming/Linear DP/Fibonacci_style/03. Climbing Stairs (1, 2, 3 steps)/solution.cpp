#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1 or n == 0)
      return 1;

    if (n == 2)
      return 2;

    int p1 = 1, p2 = 1, p3 = 2;
    for (int i = 3; i <= n; i++) {
      int curr = p1 + p2 + p3;
      p1 = p2;
      p2 = p3;
      p3 = curr;
    }
    return p3;
  }
};
