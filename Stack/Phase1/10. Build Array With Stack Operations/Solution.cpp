#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    stack<int> st;
    int completed = 0;
    vector<string> res;
    for (int i = 1; i <= n; i++) {
      if (completed == target.size()) {
        break;
      }

      st.push(i);
      res.push_back("Push");

      if (i == target[completed]) {
        completed++;
      } else {
        st.pop();
        res.push_back("Pop");
      }
    }
    return res;
  }
};
