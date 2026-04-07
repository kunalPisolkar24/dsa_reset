#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> evenOddSort(vector<int> arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {

      if (a % 2 == 0 and b % 2 != 0)
        return true;
      else if (a % 2 != 0 and b % 2 == 0)
        return false;

      if (a % 2 == 0 and b % 2 == 0)
        return a < b;
      if (a % 2 != 0 and b % 2 != 0)
        return a > b;

      return false;
    });
    return arr;
  }
};
