#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int sumOfDigits(int N) {
    function<int(int)> sol = [&](int n) -> int {
      if (n <= 0)
        return 0;
      int tempVal = n % 10;
      return tempVal + sol(n / 10);
    };
    if (N < 0)
      N *= -1;
    return sol(N);
  }
};
