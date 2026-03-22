#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> reverseArray(vector<int> &arr) {
    vector<int> res;
    stack<int> s;
    for (int i : arr) {
      s.push(i);
    }

    while (!s.empty()) {
      res.push_back(s.top());
      s.pop();
    }
    return res;
  }
};
