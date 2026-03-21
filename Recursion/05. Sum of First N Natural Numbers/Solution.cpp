#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int sumFirstN(int N) {
    function<int(int)> sol = [&](int n) -> int {
      if (n < 0)
        return 0;
      return n + sol(n - 1);
    };
    return sol(N);
  }
};
