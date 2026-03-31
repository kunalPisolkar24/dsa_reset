#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string convertToBinary(int n) {
    function<string(int)> sol = [&](int n) -> string {
      if (n == 1)
        return "1";
      if (n == 0)
        return "0";
      return sol(n / 2) + to_string(n & 1);
    };
    return sol(n);
  }
};
