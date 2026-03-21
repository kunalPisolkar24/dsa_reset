#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countDigits(int N) {
    if(N == 0) return 1;
    function<int(int)> sol = [&](int n) -> int {
      if (n <= 0)
        return 0;
      return 1 + sol(n / 10);
    };
    if(N < 0) N *= -1;
    return sol(N);
  }
};
