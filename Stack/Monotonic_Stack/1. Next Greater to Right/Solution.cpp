#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterRight(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() and st.top() <= arr[i]) {
        st.pop();
      }
      res[i] = st.empty() ? -1 : st.top();
      st.push(arr[i]);
    }
    return res;
  }
};
