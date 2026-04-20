#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> distanceToNextGreater(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n);
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() and st.top().first <= arr[i]) {
        st.pop();
      }
      res[i] = st.empty() ? -1 : (st.top().second - i);
      st.push({arr[i], i});
    }
    return res;
  }
};
