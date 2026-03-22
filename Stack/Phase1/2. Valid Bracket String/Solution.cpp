#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    string opening = "{[(";
    stack<char> st;
    for (auto i : s) {
      if (opening.find(i) != string::npos) {
        st.push(i);
      } else {
        if (!st.empty()) {
          if (st.top() == '(' and i == ')')
            st.pop();
          else if (st.top() == '[' and i == ']')
            st.pop();
          else if (st.top() == '{' and i == '}')
            st.pop();
          else
            return false;
        } else
          return false;
      }
    }
    return st.empty();
  }
};
