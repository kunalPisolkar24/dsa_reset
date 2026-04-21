#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> stockSpan(vector<int> &prices) {
    int n = prices.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() and prices[st.top()] <= prices[i]) {
        st.pop();
      }
      res[i] = st.empty() ? i + 1 : (i - st.top());
      st.push(i);
    }
    return res;
  }
};
