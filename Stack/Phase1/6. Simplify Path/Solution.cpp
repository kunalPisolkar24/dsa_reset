#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    stack<string> st;
    string token;
    stringstream ss(path);

    while (getline(ss, token, '/')) {
      if (token.empty() or token == ".")
        continue;
      if (token == "..") {
        if (!st.empty())
          st.pop();
      } else {
        cout << token << endl;
        st.push(token);
      }
    }

    vector<string> tokens;
    while (!st.empty()) {
      tokens.push_back(st.top());
      st.pop();
    }
    reverse(tokens.begin(), tokens.end());

    string res;
    for (auto i : tokens) {
      res += "/" + i;
    }
    return res.empty() ? "/" : res;
  }
};
