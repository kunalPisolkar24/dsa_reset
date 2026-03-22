#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;

    for (auto i : s) {
      if (st.empty()) {
        st.push({i, 1});
        continue;
      }

      if (st.top().first == i) {
        st.push({i, st.top().second + 1});
        if (st.top().second >= k) {
          int temp = k;
          while (!st.empty() and temp--) {
            st.pop();
          }
        }
      } else {
        st.push({i, 1});
      }
    }

    string res;
    while (!st.empty()) {
      res += st.top().first;
      st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
  }
};
