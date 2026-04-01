#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        vector<int> current;
        backtrack(arr, 0, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& arr, int start, int currentSum, int target, vector<int>& current, vector<vector<int>>& result) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < (int)arr.size(); i++) {
            // Handle duplicates: skip if current element is same as previous in the same loop level
            if (i > start && arr[i] == arr[i - 1]) {
                continue;
            }

            // Pruning: since elements are positive and sorted, if current + arr[i] > target, all subsequent elements will also exceed.
            if (currentSum + arr[i] > target) {
                break;
            }

            current.push_back(arr[i]);
            backtrack(arr, i + 1, currentSum + arr[i], target, current, result);
            current.pop_back();
        }
    }
};
