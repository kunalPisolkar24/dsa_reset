#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> sortByDistance(vector<int> arr, int k) {
    sort(arr.begin(), arr.end(), [&](int a, int b) {
      long long d1 = llabs((long long)a - k);
      long long d2 = llabs((long long)b - k);

      if (d1 == d2)
        return a < b;
      return d1 < d2;
    });
    return arr;
  }
};
