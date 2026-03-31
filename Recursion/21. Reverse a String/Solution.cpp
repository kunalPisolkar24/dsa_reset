#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string reverseString(string s) {
    string temp = s;

    function<void(int, int)> sol = [&](int low, int high) -> void {
      if (low > high)
        return;
      swap(temp[low], temp[high]);
      sol(low + 1, high - 1);
    };
    sol(0, temp.size() - 1);
    return temp;
  }
};
