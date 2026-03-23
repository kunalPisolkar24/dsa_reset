#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool backspaceCompare(string s, string t) {
    string a, b;
    for (auto i : s) {
      if (!a.empty() and i == '#') {
        a.pop_back();
      } else
        if(i != '#') 
            a.push_back(i);
    }

    for(auto i: t) {
      if (!b.empty() and i == '#') {
        b.pop_back();
      } else
        if(i != '#') 
            b.push_back(i);
    }
    return a == b;
  }
};
