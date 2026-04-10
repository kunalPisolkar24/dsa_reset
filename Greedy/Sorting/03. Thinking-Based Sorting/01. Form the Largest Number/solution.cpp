#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string largestNumber(vector<int> arr) {
    sort(arr.begin(), arr.end(), [](int &a, int &b) {
      string x = to_string(a), y = to_string(b);
      if (x == y)
        return x.length() < y.length();
      return x + y > y + x;
    });
    if (arr[0] == 0) return "0";
    string res;
    for (auto i : arr) {
      res += to_string(i);
    }
    return res;
  }
};
