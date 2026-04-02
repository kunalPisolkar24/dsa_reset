#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> subsequences(string s) {
    vector<string> res;
    int n = s.size();
    function<void(string &, int)> sol = [&](string &temp, int idx) -> void {
      if (idx >= n) {
        res.push_back(temp);
        return;
      }

      sol(temp, idx + 1);

      temp.push_back(s[idx]);
      sol(temp, idx + 1);
      temp.pop_back();
    };
    string temp;
    sol(temp, 0);
    return res;
  }
};
