#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    long long mx = 0;
    int n = heights.size();
    auto smallestOnLeft = [&]() -> vector<int> {
      vector<int> res(n, 0);
      stack<int> st;
      for (int i = 0; i < n; i++) {
        while (!st.empty() and heights[st.top()] >= heights[i]) {
          st.pop();
        }
        res[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return res;
    };

    auto smallestOnRight = [&]() -> vector<int> {
      vector<int> res(n, 0);
      stack<int> st;
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() and heights[st.top()] >= heights[i]) {
          st.pop();
        }
        res[i] = st.empty() ? n : st.top();
        st.push(i);
      }
      return res;
    };

    vector<int> left = smallestOnLeft(), right = smallestOnRight();

    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        mx = max(mx, (long long) heights[i] * width);
    }
    return mx;
  }
};
