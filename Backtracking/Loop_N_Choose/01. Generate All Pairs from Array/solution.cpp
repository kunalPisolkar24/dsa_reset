#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generatePairs(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(arr, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& arr, int start, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == 2) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < (int)arr.size(); i++) {
            current.push_back(arr[i]);
            backtrack(arr, i + 1, current, result);
            current.pop_back();
        }
    }
};
