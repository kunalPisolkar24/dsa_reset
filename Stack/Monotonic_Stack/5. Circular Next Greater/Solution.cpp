#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterCircular(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> res(n);
    for (int i = 2 * n - 1; i >= 0; i--) {
      while (!st.empty() and st.top() <= arr[i % n]) {
        st.pop();
      }
      if (i < n)
        res[i % n] = st.empty() ? -1 : st.top();
      st.push(arr[i % n]);
    }
    return res;
  }
};
