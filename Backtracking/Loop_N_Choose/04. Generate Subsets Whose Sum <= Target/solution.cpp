#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithSumLimit(vector<int>& arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(arr, 0, 0, target, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& arr, int start, int currentSum, int target, vector<int>& current, vector<vector<int>>& result) {
        // Since elements are non-negative, if we reach this point, currentSum <= target.
        // Also, every node is a valid subset.
        result.push_back(current);

        for (int i = start; i < (int)arr.size(); i++) {
            // Pruning: if adding arr[i] exceeds target, no need to explore this branch further.
            if (currentSum + arr[i] <= target) {
                current.push_back(arr[i]);
                backtrack(arr, i + 1, currentSum + arr[i], target, current, result);
                current.pop_back();
            }
        }
    }
};
