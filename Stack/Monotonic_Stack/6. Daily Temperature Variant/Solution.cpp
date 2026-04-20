#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> dailyTempVariant(vector<int> &temps) {
    int n = temps.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      int target = temps[i] + 3;
      while (!st.empty() and temps[st.top()] < target) {
        st.pop();
      }

      res[i] = st.empty() ? -1 : (st.top() - i);
      st.push(i);
    }
    return res;
  }
};
