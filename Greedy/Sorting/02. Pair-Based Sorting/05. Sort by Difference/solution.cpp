#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> sortByDifference(vector<pair<int, int>> arr) {
        sort(arr.begin(), arr.end(), [](pair<int,int> &a, pair<int,int>&b) {
            int x = a.first - a.second;
            int y = b.first - b.second;
            if(x == y) {
                return a.first < b.first;
            }
            return x < y;
        });
        return arr;
    }
};
