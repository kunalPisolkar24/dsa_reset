#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<pair<int, int>> sortByStart(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(),
         [](pair<int, int> &a, pair<int, int> &b) {
           if (a.first == b.first)
             return a.second < b.second;
           return a.first < b.first;
         });
    return intervals;
  }

  vector<pair<int, int>> sortByEnd(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(),
         [](pair<int, int> &a, pair<int, int> &b) {
           if (a.second == b.second)
             return a.first < b.first;
           return a.second < b.second;
         });
    return intervals;
  }

  vector<pair<int, int>> sortByLength(vector<pair<int, int>> intervals) {
    sort(intervals.begin(), intervals.end(),
         [](pair<int, int> &a, pair<int, int> &b) {
           int x = abs(a.second - a.first), y = abs(b.second - b.first);
           if (x == y)
             return a.first < b.first;
           return x < y;
         });
    return intervals;
  }
};
