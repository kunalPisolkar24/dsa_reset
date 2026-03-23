#include <bits/stdc++.h>
#include <cctype>

using namespace std;

class Solution {
public:
  string makeGood(string s) {
    string temp;

    auto isLower = [&](char c) -> bool { return (c >= 'a' and c <= 'z'); };

    auto isUpper = [&](char c) -> bool { return (c >= 'A' and c <= 'Z'); };

    for (auto i : s) {
      if (temp.empty()) {
        temp.push_back(i);
      } else {
        if (isLower(temp.back()) and isUpper(i) and temp.back() == i + 32)
          temp.pop_back();
        else if (isUpper(temp.back()) and isLower(i) and temp.back() == i - 32) {
          temp.pop_back();
        } else
          temp.push_back(i);
      }
    }
    return temp;
  }
};
