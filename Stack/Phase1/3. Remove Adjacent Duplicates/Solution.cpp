#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string removeDuplicates(string s) {
    string res = "";
    for (auto i : s) {
      if (res.empty()) {
        res.push_back(i);
        continue;
      }
      if (!res.empty() and i == res.back()) {
        res.pop_back();
      } else
        res.push_back(i);
    }
    return res;
  }
};
