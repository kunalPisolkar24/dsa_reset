#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> printNTo1(int N) {
    vector<int> res;
    function<void(int)> sol = [&](int n) -> void {
      if (n < 1)
        return;
      res.push_back(n);
      sol(n - 1);
    };
    sol(N);
    return res;
  }
};
