#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countZeros(int N) {
    if(N == 0) return 1;
    function<int(int)> sol = [&](int n) -> int {
      if (n <= 0)
        return 0;
      int temp = n % 10;
      return (temp == 0) + sol(n / 10);
    };
    if (N < 0)
      N *= -1;
    return sol(N);
  }
};
