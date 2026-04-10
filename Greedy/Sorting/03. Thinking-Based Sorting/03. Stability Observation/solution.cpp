#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<pair<int, char>> stableSortByValue(vector<pair<int, char>> arr) {
    stable_sort(arr.begin(), arr.end(),
                [](const pair<int, char> &a, const pair<int, char> &b) {
                  return a.first < b.first;
                });
    return arr;
  }
};
