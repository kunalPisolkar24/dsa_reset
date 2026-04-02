#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> generate(int n) {
    vector<string> res;
    function<void(string&)> sol = [&](string &temp) -> void {
      if (temp.size() == n) {
        res.push_back(temp);
        return;
      }

      temp.push_back('0');
      sol(temp);
      temp.pop_back();

      temp.push_back('1');
      sol(temp);
      temp.pop_back();
    };
    string temp;
    sol(temp);
    return res;
  }
};
