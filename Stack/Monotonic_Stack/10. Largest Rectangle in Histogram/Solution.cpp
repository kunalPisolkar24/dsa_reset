#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    long long mx = 0;
    int n = heights.size();
    stack<int> st;
    for (int i = 0; i <= n; i++) {
      int curr = (i == n ? 0 : heights[i]);
      while (!st.empty() and heights[st.top()] > curr) {
        int height = heights[st.top()];
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int right = i;
        long long width = right - left - 1;
        mx = max(mx, 1LL * height * width);
      }
      st.push(i);
    }
    return (int)mx;
  }
};
