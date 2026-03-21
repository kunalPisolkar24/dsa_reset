#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  long long factorial(int N) {
    function<long long(int)> sol = [&](int n) -> long long {
      if (n == 0 or n == 1)
        return 1;
      return n * sol(n - 1);
    };

    return sol(N);
  }
};
