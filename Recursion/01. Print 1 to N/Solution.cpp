#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> print1ToN(int N) {
    vector<int> res;
    function<void(int)> sol = [&](int n) -> void {
      if (n > N)
        return;
      res.push_back(n);
      sol(n + 1);
    };
    sol(1);
    return res;
  }
};
