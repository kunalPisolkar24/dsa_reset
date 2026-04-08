#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> sortBySecond(vector<pair<int, int>> arr) {
    sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if(a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    return arr;
  }
};
