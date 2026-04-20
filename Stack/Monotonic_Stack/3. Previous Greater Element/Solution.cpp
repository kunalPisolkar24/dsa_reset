#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> previousGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() and st.top() <= arr[i])
        st.pop();

      res[i] = st.empty() ? -1 : st.top();
      st.push(arr[i]);
    }
    return res;
  }
};
