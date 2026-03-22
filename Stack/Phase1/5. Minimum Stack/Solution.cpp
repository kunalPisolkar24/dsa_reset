#include <bits/stdc++.h>

using namespace std;

class MinStack {
  stack<pair<int, int>> st;

public:
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      st.push({val, val});
    } else {
      st.push({val, min(st.top().second, val)});
    }
  }

  void pop() {
    if(st.empty()) return;
    st.pop();
  }

  int top() {
    if(st.empty()) return -1;
    return st.top().first;
  }

  int getMin() {
    if(st.empty()) return -1;
    return st.top().second;
  }
};
