#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> sortAscending(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
  }

  vector<int> sortDescending(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());
    return arr;
  }

  vector<int> sortByDistance(vector<int> arr, int k) {
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      int x = abs(a - k), y = abs(b - k);
      if(x == y) {
        return a < b;
      }
      return x < y;
    });
    return arr;
  }
};
