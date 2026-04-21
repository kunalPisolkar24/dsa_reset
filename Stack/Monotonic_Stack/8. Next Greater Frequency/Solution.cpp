#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterFrequency(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n);
    // index of element
    stack<int> st;

    unordered_map<int, int> ump;
    for (auto i : arr) {
      ump[i]++;
    }

    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() and ump[arr[st.top()]] <= ump[arr[i]]) {
        st.pop();
      }
      res[i] = st.empty() ? -1 : arr[st.top()];
      st.push(i);
    }
    return res;
  }
};
